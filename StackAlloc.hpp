#ifndef STACK_ALLOC_H
#define STACK_ALLOC_H

#include <memory>

template <typename T>
struct StackNode_{
    T data;
    StackNode_ *prev;
};

template<typename T, typename Alloc = std::allocator<T>>
class StackAlloc{
public:
    typedef StackNode_<T> Node;
    typedef typename Alloc::template rebind<Node>::other allocator;

    StackAlloc(){ head_ = nullptr; }
    ~StackAlloc() { clear(); }

    bool empty() const { return (head_ == nullptr); }

    T top() const { return head_->data; }
private:
    allocator allocator_;
    Node *head_;

public:
void clear(){
    Node *curr = head_;
    while(curr != nullptr){
        Node *temp = curr->prev;
        allocator_.destroy(curr);
        allocator_.deallocate(curr, 1);
        curr = temp;
    }
    head_ = nullptr;
}

void push(T element){
    Node *newNode = allocator_.allocate(1);
    allocator_.construct(newNode, Node());

    newNode->data = element;
    newNode->prev = head_;
    head_ = newNode;
}

T pop(){
    T result = head_->data;
    Node *tmp = head_->prev;
    allocator_.destroy(head_);
    allocator_.deallocate(head_, 1);
    head_ = tmp;
    return result;
}
};

#endif // STACK_ALLOC_H
