解题思路简单描述：
- 使用长度为capacity的整型数组int[]来存储元素。
- 使用putIndex及takeIndex这两个变量来记录当前入队/出队的数组下标，使用count来记录当前素组中的元素个数。
- 使用ReentrantLock及两个Condition来完成线程间同步。 
```
class BoundedBlockingQueue {
    private int[] items;

    private int putIndex;
    private int takeIndex;
    private int count;

    private ReentrantLock lock;
    private Condition notFull;
    private Condition notEmpty;

    public BoundedBlockingQueue(int capacity) {
        this.items = new int[capacity];

        this.lock = new ReentrantLock();
        this.notFull = this.lock.newCondition();
        this.notEmpty = this.lock.newCondition();
    }
    
    public void enqueue(int element) throws InterruptedException {
        final ReentrantLock lock = this.lock;

        lock.lock();
        try {
            while (this.count == this.items.length) {
                this.notFull.await();
            }

            this.items[this.putIndex] = element;
            if (++this.putIndex == this.items.length) {
                this.putIndex = 0;
            }

            this.count++;
            this.notEmpty.signal();
        } finally {
            lock.unlock();
        }
    }
    
    public int dequeue() throws InterruptedException {
        ReentrantLock lock = this.lock;

        lock.lock();
        try {
            while (this.count == 0) {
                this.notEmpty.await();
            }

            int val = this.items[this.takeIndex];
            if (++this.takeIndex == this.items.length) {
                this.takeIndex = 0;
            }

            this.count--;
            this.notFull.signal();
            return val;
        } finally {
            lock.unlock();
        }
    }
    
    public int size() {
        ReentrantLock lock = this.lock;

        lock.lock();
        try {
            return this.count;
        } finally {
            lock.unlock();
        }
    }
}
```
