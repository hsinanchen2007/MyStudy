```

class BoundedBlockingQueue {

    private LinkedList<Integer> queue;
    private final Lock lock;
    private final Condition isFull;
    private final Condition isEmpty;
    private final int capactiy;
    
    public BoundedBlockingQueue(int capacity) {
        this.lock = new ReentrantLock(true);
        isEmpty = lock.newCondition();
        isFull = lock.newCondition();
        queue = new LinkedList<>();
        this.capactiy = capacity;
    }
    
    // 入队列头
    public void enqueue(int element) throws InterruptedException {
        lock.lock();
        try {
            while (queue.size() == capactiy){
                isFull.await();
            }
            queue.offerFirst(element);
            isEmpty.signalAll();
        }finally {
            lock.unlock();
        }

    }
    
    //删除队尾元素
    public int dequeue() throws InterruptedException {
        int res = 0;
        lock.lock();
        try {
            while (queue.isEmpty()){
                isEmpty.await();
            }

            res = queue.pollLast();
            isFull.signalAll();
        }finally {
            lock.unlock();
            return res;
        }
    }

    public int size() {
        return queue.size();
    }
}
```
