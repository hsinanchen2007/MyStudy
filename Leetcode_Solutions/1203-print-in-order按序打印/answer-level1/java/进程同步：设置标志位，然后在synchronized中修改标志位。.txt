### 解题思路
此处撰写解题思路
`synchronized`**是用来同步同一个进程的不同线程**，通过设置标志位来同步不同进程`firstFinish`
lock.notify()随机唤醒一个。
lock.notify()唤醒所有等待次资源的进程。
### 代码

```java
class Foo {
    private boolean  firstFinish;
    private boolean secondFinish;
    private final Object lock=new Object();
    public Foo() {

    }

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized (lock){
            printFirst.run();
            firstFinish=true;
            lock.notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized (lock){
            while (!firstFinish) lock.wait();
            printSecond.run();
            secondFinish=true;
            lock.notifyAll();
        }


    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized (lock){
            while (!secondFinish)lock.wait();
            printThird.run();
        }

        
    }
}
```