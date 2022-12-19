第一个是阻塞队列，基于链表用两个mutex去维护首尾指针。
[BlockingQueue](https://github.com/bhhbazinga/BlockingQueue)

下面是这个是基于链表的无锁队列实现，与Java8里的ConcurrentLinkedQueue实现采用了同一篇论文：
Simple, Fast, and Practical Non-Blocking and Blocking Concurrent Queue Algorithms. Maged M. Michael Michael L. Scott
另外，我们用RAII风格的风险指针去管理内存
[ConcurrentQueue](https://github.com/bhhbazinga/ConcurrentQueue)
