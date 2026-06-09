### 解题思路
使用原始的wait()和notifyAll来控制线程，使用字符串常量来当锁，减少开销，直接从常量池里面取，CountDownLatch 和 信号量都行，但我还是偏向于原始写法

### 代码

```java
class Foo {

    private volatile boolean firstFinish;

    private volatile boolean secondFinish;

    private final String lock = "java".intern();

    public Foo() {}

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        synchronized(lock) {
            printFirst.run();
            firstFinish = true;
            lock.notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized(lock){
            while (!firstFinish)
                lock.wait();
            // printSecond.run() outputs "second". Do not change or remove this line.
            printSecond.run();
            secondFinish = true;
            lock.notifyAll();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized(lock){
            while (!secondFinish)
                lock.wait();
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}

```