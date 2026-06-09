### 解题思路
五个可重入锁用来限制叉子的使用，可重入锁相当于一个队列，当上一个人在使用这个叉子的时候，下一个人被阻塞住，如果有多个人阻塞，则都会阻塞，然后依次解锁获取叉子。

一个最多允许四个哲学家同时就餐的信号量，为了避免死锁。

官方的OJ可能有问题，同样的代码第一次提交解答错误，但是第二次提交就通过了。。。

### 代码

```java
 class DiningPhilosophers {
    Semaphore semaphore = new Semaphore(4);
    ReentrantLock[] locks = new ReentrantLock[5];

    public DiningPhilosophers() {
        for (int i = 0; i < locks.length; i++) {
            locks[i] = new ReentrantLock();
        }
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        int left = philosopher;
        int right = (philosopher+1)%5;
        semaphore.acquire();
        locks[left].lock();
        locks[right].lock();
        pickLeftFork.run();
        pickRightFork.run();
        eat.run();
        putLeftFork.run();
        putRightFork.run();
        locks[left].unlock();
        locks[right].unlock();
        semaphore.release();
    }
}
```

### 简单方法

除了上面用一个信号量和五个锁的方法，还有一个简单的方法就是用五个信号量分表表示是否允许对应的哲学家就餐，每次只允许一个哲学家就餐，其他四个保持等待，每次只解锁下一个哲学家。如果`0`个哲学家吃完了就解锁第`1`个，第`1`个哲学家吃完了就解锁第`2`个，依次类推。

```java
class DiningPhilosophers {
    Semaphore[] semaphores = new Semaphore[5];

    public DiningPhilosophers() {
        for (int i = 0; i < semaphores.length; i++) {
            semaphores[i] = new Semaphore(0);
        }
        semaphores[0].release();
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        semaphores[philosopher].acquire();
        pickLeftFork.run();
        pickRightFork.run();
        eat.run();
        putLeftFork.run();
        putRightFork.run();
        semaphores[(philosopher+1)%5].release();
    }
}
```