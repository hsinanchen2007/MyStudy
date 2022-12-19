### 解题思路

1. 用 Semaphore 同步叉子的状态, 只要当前叉子没有被占用就允许被其他哲学家拿起
2. 让一部分人先拿左边的叉子, 另一部分人先拿右边的叉子, 避免死锁 (所有哲学家都拿起左边的叉子等待右边的叉子)

<br>

**但是, 我觉得官方的Java测试用例好像有点问题**

当发生如下场景: `哲学家1拿起左边的叉子, 而其右边的叉子被旁边的哲学家2拿起` 时, 官方的测试用例可能会不通过.

但根据题目描述, 这种情况(即不保证一个哲学家拿起两把叉子的原子性)应该是允许发生的. 

在修改后的版本A代码中我避免了这种情况的发生, 才最终得以通过测试.

原本的实现代码(版本B)和我自己的测试用例也附在本题解的末尾.


### 版本A

```java
class DiningPhilosophers {

    private volatile Semaphore[] forks = new Semaphore[]{
            new Semaphore(1),
            new Semaphore(1),
            new Semaphore(1),
            new Semaphore(1),
            new Semaphore(1),
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

        int leftForkNo = philosopher;
        int rightForkNo = (philosopher + 1) % 5;

        if (philosopher % 2 == 0) {
            forks[leftForkNo].acquire();
            forks[rightForkNo].acquire();
        } else {
            forks[rightForkNo].acquire();
            forks[leftForkNo].acquire();
        }

        pickLeftFork.run();
        pickRightFork.run();

        eat.run();

        putLeftFork.run();
        putRightFork.run();

        forks[leftForkNo].release();
        forks[rightForkNo].release();
    }
}
```



### 版本B

```java
class DiningPhilosophers {

    private volatile Semaphore[] forks = new Semaphore[]{
            new Semaphore(1),
            new Semaphore(1),
            new Semaphore(1),
            new Semaphore(1),
            new Semaphore(1),
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

        int leftForkNo = philosopher;
        int rightForkNo = (philosopher + 1) % 5;

        if (philosopher % 2 == 0) {
            forks[leftForkNo].acquire();
            pickLeftFork.run();

            forks[rightForkNo].acquire();
            pickRightFork.run();
        } else {
            forks[rightForkNo].acquire();
            pickRightFork.run();

            forks[leftForkNo].acquire();
            pickLeftFork.run();
        }

        eat.run();

        putLeftFork.run();
        forks[leftForkNo].release();

        putRightFork.run();
        forks[rightForkNo].release();
    }
}
```


### 测试用例

```java
public class DiningPhilosophersTest {

    @Rule
    public final SystemOutRule systemOutRule = new SystemOutRule().enableLog();

    @Test
    public void test() throws InterruptedException {
        DiningPhilosophers diningPhilosophers = new DiningPhilosophers();

        List<int[]> output = new CopyOnWriteArrayList<>();
        List<Thread> philosophers = new ArrayList<>();

        int peopleNum = 5;
        int eatTime = 1;

        for (int i = 0; i < peopleNum; i++) {
            int philosopherNum = i;
            Thread philosopher = new Thread(new Runnable() {
                @SneakyThrows
                @Override
                public void run() {
                    for (int j = 0; j < eatTime; j++) {
                        diningPhilosophers.wantsToEat(
                                philosopherNum,
                                () -> output.add(new int[]{philosopherNum, 1, 1}),
                                () -> output.add(new int[]{philosopherNum, 2, 1}),
                                () -> output.add(new int[]{philosopherNum, 0, 3}),
                                () -> output.add(new int[]{philosopherNum, 1, 2}),
                                () -> output.add(new int[]{philosopherNum, 2, 2})
                        );
                    }
                }
            });
            philosophers.add(philosopher);
            philosopher.start();
        }

        for (Thread philosopher : philosophers) {
            philosopher.join();
        }

        HashMap<Integer, Boolean> forkMap = new HashMap<>();

        for (int[] action : output) {
            int id = action[0];
            int side = action[1];
            int move = action[2];

            // pick up
            if (move == 1) {
                int forkNo = id + side;
                if (forkNo == peopleNum + 1) {
                    forkNo = 1;
                }
                Boolean occupied = forkMap.getOrDefault(forkNo, false);
                if (occupied) {
                    fail("the " + forkNo + "th fork is occupied !");
                }
                forkMap.put(forkNo, true);
            }

            // put down
            if (move == 2) {
                int forkNo = id + side;
                if (forkNo == peopleNum + 1) {
                    forkNo = 1;
                }
                Boolean occupied = forkMap.getOrDefault(forkNo, false);
                if (!occupied) {
                    fail("the " + forkNo + "th fork is not yours !");
                }
                forkMap.put(forkNo, false);
            }
        }
    }

}
```