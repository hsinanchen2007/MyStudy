### 解题思路
为每个叉子设置一个锁，左手边的叉子的位置为哲学家的位置，右手边的叉子的位置为哲学家的位置+1，或者0（哲学家位置为4的时候）。
设置最大可进食的信号，数量为哲学家数量-2，因为超过这个信号量之后，无论哲学家的位置为何，下一个人都无法拿到叉子，更大的信号量反而性能更差。
其实还有个问题，按道理来说，只要叉子放下，其他人就可以拿起进食了，但是不知道为什么，如果那么设计，系统会报错。
### 代码

```java
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class DiningPhilosophers {
    private int total = 5;
    private Semaphore semaphore = new Semaphore((total-2);
    private Lock[] locks = {
            new ReentrantLock(),
            new ReentrantLock(),
            new ReentrantLock(),
            new ReentrantLock(),
            new ReentrantLock(),
    };

    public DiningPhilosophers() {
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        semaphore.acquire();
        Lock left = locks[philosopher];
        Lock right = locks[(philosopher == total - 1) ? 0 : (philosopher + 1)];
        left.lock();
        right.lock();
        pickLeftFork.run();
        pickRightFork.run();
        eat.run();
        putLeftFork.run();
        putRightFork.run();
        left.unlock();
        right.unlock();
        semaphore.release();
    }
}
```