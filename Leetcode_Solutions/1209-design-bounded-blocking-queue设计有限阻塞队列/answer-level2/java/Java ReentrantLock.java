

```java
class BoundedBlockingQueue {

    private int putIndex, getIndex, size, capacity;
    private int[] items;

    private Lock lock = new ReentrantLock();
    private Condition notFull = lock.newCondition();
    private Condition notEmpty = lock.newCondition();

    public BoundedBlockingQueue(int capacity) {
        this.capacity = capacity;
        items = new int[capacity];
    }
    
    public void enqueue(int element) throws InterruptedException {
        lock.lock();
        try{
            while (size == capacity)
                notFull.await();
            items[putIndex++] = element;
            putIndex %= capacity;
            notEmpty.signal();
            size++;
        }finally{
            lock.unlock();
        }
    }
    
    public int dequeue() throws InterruptedException {
        lock.lock();
        try{
            while (size == 0)
                notEmpty.await();
            int element = items[getIndex++];
            getIndex %= capacity;
            size--;
            notFull.signal();
            return element;
        }finally{
            lock.unlock();
        }     
    }
    
    public int size() {
        return size;
    }
}
```