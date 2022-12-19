```java []
import java.util.concurrent.Semaphore;
class Foo {

    public Semaphore semaphore = new Semaphore(0);
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        semaphore.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        semaphore.acquire();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        semaphore.release(2);
    }

    public void third(Runnable printThird) throws InterruptedException {
        semaphore.acquire(2);
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```