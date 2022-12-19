### 解题思路
此处撰写解题思路

### 代码

```java

public class Foo {
    private Lock lock = new ReentrantLock();
    private Condition condition1 = lock.newCondition();
    private Condition condition2 = lock.newCondition();
    private Condition condition3 = lock.newCondition();
    private volatile int number;
    public Foo() {
        number = 1;
    }

    public void first(Runnable printFirst) throws InterruptedException {
        lock.lock();
        while (number != 1) {
            condition1.await();
        }
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        number = 2;
        condition2.signal();
        lock.unlock();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        lock.lock();
        while (number != 2) {
            condition2.await();
        }
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        number = 3;
        condition3.signal();
        lock.unlock();
    }

    public void third(Runnable printThird) throws InterruptedException {
        lock.lock();
        while (number != 3) {
            condition3.await();
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        number = 1;
        condition1.signal();
        lock.unlock();
    }
}

```