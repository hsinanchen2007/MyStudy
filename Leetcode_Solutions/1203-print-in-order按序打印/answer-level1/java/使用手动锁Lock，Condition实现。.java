### 解题思路
  这个题实际意义就是考察线程之间的通信
+ 信号量 
+ Condition： 一个资源对应3个线程，那么3个线程创建对应Condition
### 代码

```java
class Foo {

    private int flag = 1;
    private Lock lock = new ReentrantLock();
    // 每个线程需要一个condition
    private Condition one = lock.newCondition();
    private Condition two = lock.newCondition();
    private Condition three = lock.newCondition();
    public Foo() { }

    public void first(Runnable printFirst) throws InterruptedException {
        lock.lock();
        try {
            while (flag != 1) { one.await(); }
            flag = 2; 
            printFirst.run();
            two.signal();
        } finally {
            lock.unlock();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        lock.lock();
        try {
            while (flag != 2) { two.await(); }
            flag = 3;
            printSecond.run();
            three.signal();
        } finally {
            lock.unlock();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        lock.lock();
        try {
            while (flag != 3) { three.await(); }
            flag = 1;
            printThird.run();
            one.signal();
        } finally {
            lock.unlock();
        }
    }
}
```