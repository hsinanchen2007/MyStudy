### 解题思路
每个任务按照在执行序列中的顺序号来触发。这样可以形成一个模板，适用于各种情况，只要是一个task 序列。
此外，这个序列是可以多次执行的。

下面的代码中， TotalSteps是这个task序列的任务个数， rounds是这个序列重复的次数。
按需修改即可。

### 代码

```java
class FooBar {
    private Object lock = new Object();
    private volatile AtomicInteger stepIndex = new AtomicInteger();
    private final int TotalSteps = 2;

    private int rounds;

    public FooBar(int n) {
        this.stepIndex.set(0);
        this.rounds = n;
    }

    protected void procTemplate(Runnable runObj, int myIndex) throws InterruptedException {
        synchronized (lock) {
            while (this.stepIndex.get() != myIndex) {
                lock.wait();
            }

            runObj.run();

            stepIndex.getAndIncrement();
            if (stepIndex.get() >= TotalSteps)
                stepIndex.set(0);

            lock.notifyAll();
        }
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < rounds; i++) {
            this.procTemplate(printFoo, 0);
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < rounds; i++) {
            this.procTemplate(printBar, 1);
        }
    }
}

```