**方法一**：知道JDK有现成阻塞队列。
```
import java.util.*;
class BoundedBlockingQueue {
    // JDK 的阻塞队列，这是用数组实现的，可以尝试其他的实现，与自己的对比一下性能
    private ArrayBlockingQueue<Integer> blockQueue;

    public BoundedBlockingQueue(int capacity) {
        blockQueue = new ArrayBlockingQueue<>(capacity);
    }

    // 进队列
    public void enqueue(int element) throws InterruptedException {
        blockQueue.put(element);
    }

    // 出队列
    public int dequeue() throws InterruptedException {
        return blockQueue.take();
    }
    
    public int size() {
        return blockQueue.size();
    }
}
```

**方法二**：只使用了一个 volatile 变量，我觉得不太对，但是居然过了。。。因为 volatile 并发的时候只保证多线程之间的**可见性**，或者那个大佬看见可以给我指点一哈。
```
class BoundedBlockingQueue {
    private  volatile int size;
    private int capacity;
    private int[] queue;
    // 指向队头的指针
    private  int last;   
    // 指向队列尾
    private  int first;

    public BoundedBlockingQueue(int capacity) {
        size = 0;
        last = 0;
        first = 0;
        this.capacity = capacity;
        this.queue = new int[capacity+1];
    }

    // 进队列
    public void enqueue(int element) throws InterruptedException {
        while(size == capacity){}
        // 队列不满的情况下可以入队尾,在队尾添加元素
        queue[last] = element;
        last = (last + 1)% capacity;
        size ++;
    }

    // 出队列
    public int dequeue() throws InterruptedException {
        // 有元素的情况下才可以出队列,删掉队头的元素
        while(size == 0){}
        int e = queue[first];
        first = (first + 1) % capacity;
        size --;
        return e;
    }
    
    public int size() {
        return size;
    }
}
```

**方法三**：参考《Java并发编程艺术》的代码，参考的是 JDK 里阻塞队列的实现，使用**通知模式**，意思是当生产者往满的队列中添加元素的时候会被阻塞，消费者消费了队列中的元素后，会通知生产者队列不满了（notFull）；消费者面对空的队列会被阻塞，生产者往队列添加元素的时候，会通知消费者队列不空了（notEmpty）。
```
import java.util.*;
class BoundedBlockingQueue {
    private int size;
    private int capacity;
    private int[] queue;
    // 指向队头的指针
    private int last;   
    // 指向队列尾
    private int first;
    // JDK 的通知模式
    private final ReentrantLock lock;
    private final Condition notFull;
    private final Condition notEmpty;

    public BoundedBlockingQueue(int capacity) {
        this.size = 0;
        this.last = 0;
        this.first = 0;
        this.capacity = capacity;
        this.queue = new int[capacity+1];
        this.lock = new ReentrantLock();
        notFull = this.lock.newCondition();
        notEmpty = this.lock.newCondition();
    }

    // 进队列
    public void enqueue(int element) throws InterruptedException {
        // 队列不满的情况下可以入队尾,在队尾添加元素
        final ReentrantLock lock = this.lock;
        lock.lockInterruptibly();
        try{
            while(size == capacity)
                notFull.await();
            // 队列不满的情况下可以入队尾,在队尾添加元素
            queue[last] = element;
            last = (last + 1)% capacity;
            size ++;
            notEmpty.signal();
        }finally{
            lock.unlock();
        }
    }

    // 出队列
    public int dequeue() throws InterruptedException {
        // 有元素的情况下才可以出队列,删掉队头的元素
        final ReentrantLock lock = this.lock;
        lock.lockInterruptibly();
        try{
            while(size == 0)
                notEmpty.await();
            int e = queue[first];
            first = (first + 1) % capacity;
            size --;
            notFull.signal();
            return e;
        }finally{
            lock.unlock();
        }
    }
    
    public int size() {
        return size;
    }
}
```




