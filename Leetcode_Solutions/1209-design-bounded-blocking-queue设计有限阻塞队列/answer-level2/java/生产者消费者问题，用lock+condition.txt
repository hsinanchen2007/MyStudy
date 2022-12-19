```
class BoundedBlockingQueue {

    private LinkedList<Integer> queue=new LinkedList<>();
    private ReentrantLock lock=new ReentrantLock();
    private Condition empty=lock.newCondition();
    private Condition full=lock.newCondition();
    private Integer size=0;
    private Integer cap=null;

    public BoundedBlockingQueue(int capacity) {
        if(cap==null){
            lock.lock();
            try{
                if(cap==null){
                    cap=capacity;
                }
            }finally {
                lock.unlock();
            }
        }
    }

    public void enqueue(int element) throws InterruptedException {
        lock.lock();
        try{
            while(size>=cap){
                full.await();
            }
            queue.offerFirst(element);
            size+=1;
            empty.signalAll();
        }finally {
            lock.unlock();
        }
    }

    public int dequeue() throws InterruptedException {
        lock.lock();
        int res=-1;
        try {
            while(size==0){
                empty.await();
            }
            res=queue.pollLast();
            size-=1;
            full.signalAll();
        } finally {
            lock.unlock();
        }
        return res;
    }

    public int size() {
        return size;
    }
}
```
