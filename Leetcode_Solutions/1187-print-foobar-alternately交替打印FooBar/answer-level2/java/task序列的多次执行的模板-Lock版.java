### 解题思路
上一个题解（https://leetcode-cn.com/problems/print-foobar-alternately/solution/yi-ge-duo-ci-zhi-xing-task-listde-mo-ban-by-hongan/ ），用了synchronized、wait、nofityAll等来完成锁、忙退锁、唤醒。

这个题解做了改变，不用synchronized，而是Lock。Lock要用condition，await，signal等方法。
思路还是一样，根据index是否是自己的编号来触发；依然是针对hand over hand 以及 chain依赖类型多线程的通用写法。
关键点
1 lock等，要final
2 多线程共享变量，要volatile
3 判断编号==index的触发条件，要在while循环中
4 多用signalAll而不是signal

### 代码

```java
class FooBar {
    private final Lock indexLock = new ReentrantLock();
    private final Condition hitCondition = indexLock.newCondition();
    private volatile AtomicInteger stepIndex = new AtomicInteger();

    private final int TotalSteps = 2;
    private int rounds = 1;

    public FooBar(int n) {
        this.stepIndex.set(0);
        this.rounds = n;
    }

    private void procTemplate(Runnable runObj, int myIndex) throws InterruptedException {
        indexLock.lock();
        try{
            while (this.stepIndex.get() != myIndex) {
                hitCondition.await();
            }

            runObj.run();

            stepIndex.getAndIncrement();
            stepIndex.compareAndSet(TotalSteps,0);

            hitCondition.signalAll();
        }
        finally{
            indexLock.unlock();
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