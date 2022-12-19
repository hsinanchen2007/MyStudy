解决方案简单描述：
- 每个叉子对应一个ReentrantLock，拿起叉子对应获取该锁。
- 使用信号量，资源个数初始化为哲学家个数减1。每个哲学家在尝试拿起叉子前需要先获取该信号量，这样能够保证至少有一个哲学家能同时拿到左右两个叉子，以便进餐。
- 哲学家进餐后放下叉子，释放ReentrantLock及信号量。
```
class DiningPhilosophers {
    private static final int PHILOSOPHER_COUNT = 5;

    private ReentrantLock[] forkLocks = new ReentrantLock[] {
        new ReentrantLock(), new ReentrantLock(),new ReentrantLock(), 
        new ReentrantLock(), new ReentrantLock()
    };

    // 信号量，最多允许同时4个哲学家去尝试持有叉子。
    private Semaphore semaphore = new Semaphore(PHILOSOPHER_COUNT - 1);

    public DiningPhilosophers() {}

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        // 该哲学家左手边叉子编号。
        int leftForkIndex = philosopher % PHILOSOPHER_COUNT;
        // 该哲学家右手边叉子编号。
        int rightForkIndex = (philosopher + 1) % PHILOSOPHER_COUNT;

        this.semaphore.acquire(1);

        this.forkLocks[leftForkIndex].lock();
        this.forkLocks[rightForkIndex].lock();
        try {
            pickLeftFork.run();
            pickRightFork.run();

            eat.run();

            putLeftFork.run();
            putRightFork.run();
        } finally {
            this.forkLocks[rightForkIndex].unlock();
            this.forkLocks[leftForkIndex].unlock();
        }

        this.semaphore.release(1);
    }
}
```
