# MemoryPool
A High Performance Memory Pool

Picking BlockSize
-------------------------
`BlockSize` is the size of the chunks in bytes the allocator will ask from the system. It has to be large enough to contain at least two pointers or two `T` objects, depending on which is bigger. 

Picking the correct `BlockSize` is essential for good performance. I suggest you pick a power of two, which may decrease memory fragmentation depending on your system. Also, make sure that `BlockSize` is at least several hundred times larger than the size of `T` for maximum performance. The idea is, the greater the `BlockSize`, the less calls to `malloc` the library will make. However, picking a size too big might increase memory usage unnecessarily and actually decrease the performance because `malloc` may need to make many system calls.

For objects that contain several pointers, the default size of 4096 bytes should be good. If you need bigger object, you may need to time your code with larger sizes and see what works best. Unless you will be maintaining many MemoryPool objects, I do not think you need to go smaller than 4096 bytes. Though if you are working on a more limited platform (that has a copiler with C++11 support), you may need to go for smaller values. 
