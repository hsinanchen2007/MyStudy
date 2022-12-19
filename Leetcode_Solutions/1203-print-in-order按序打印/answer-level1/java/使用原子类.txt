```
import java.util.concurrent.atomic.AtomicInteger;

class Foo {

    AtomicInteger flag = new AtomicInteger(0);
    
    public Foo() {
        
    }
    
    
    public void first(Runnable printFirst) throws InterruptedException {
        // increment
        flag.getAndIncrement();
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while (!flag.compareAndSet(1, 2)){
            
        }
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
    }

    public void third(Runnable printThird) throws InterruptedException {
        while (!flag.compareAndSet(2, 3)){
            
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```
