解题思路简单描述：
- 一个水分子由两个H和一个O组成，所以定义两个信号量，初始化为2和1。
- 在水分子的生成过程中，一旦生成了两个H和一个O，那么便认为该水分子成功生成，此处H和O的先后顺序不定。
- 定义一个AtomicInteger，用于记录当前已生成了多少个H和O，如果总数为3，那么认为一个水分子成功生成，此时使用CAS重置计数并释放信号量。

```
class H2O {
    // Initialize hydrogen group (H20) limit.
    private Semaphore semaH = new Semaphore(2);
    // Initialize oxygen group (H2O) limit
    private Semaphore semaO = new Semaphore(1);
    
    // Initialize group count.
    private AtomicInteger groupCount = new AtomicInteger(0);
    
    private static final int GROUP_H_LIMIT = 2;
    private static final int GROUP_O_LIMIT = 1;
    private static final int GROUP_TOTAL_LIMIT = GROUP_H_LIMIT + GROUP_O_LIMIT;
    
    public H2O() {
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        // Try to acquire hygrogen permit.
        this.semaH.acquire(1);
    
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
    
        // Increment group molecule count.
        this.groupCount.incrementAndGet();
        
        resetIfNeeded();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        this.semaO.acquire(1);
        
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
	    releaseOxygen.run();
        
        this.groupCount.incrementAndGet();
        
        resetIfNeeded();
    }
    
    private void resetIfNeeded() {
        // If the current group is ready, release permits and try another. 
        if (this.groupCount.compareAndSet(GROUP_TOTAL_LIMIT, 0)) {
            this.semaH.release(GROUP_H_LIMIT);
            this.semaO.release(GROUP_O_LIMIT);
        }
    }
}
```
