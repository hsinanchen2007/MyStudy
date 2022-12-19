```java []
import java.util.concurrent.LinkedBlockingQueue;

class Foo {
    private LinkedBlockingQueue secondQueue;
    private LinkedBlockingQueue thirdQueue;

    public Foo() {
        secondQueue = new LinkedBlockingQueue();
        thirdQueue = new LinkedBlockingQueue();
    }

    public void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        secondQueue.put(0);
    }

    public void second(Runnable printSecond) throws InterruptedException {
        secondQueue.take();
        printSecond.run();
        thirdQueue.put(0);
    }

    public void third(Runnable printThird) throws InterruptedException {
        thirdQueue.take();
        printThird.run();
    }
}
```
