```java
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.*;
class H2O {
    
    BlockingQueue<Integer> oToH = new ArrayBlockingQueue<>(2);
    BlockingQueue<Integer> hToO = new ArrayBlockingQueue<>(2);
    
    public H2O() {
        try {
            oToH.put(0);
            oToH.put(0);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        oToH.take();
        releaseHydrogen.run();
        hToO.put(0);
    }

    public synchronized void oxygen(Runnable releaseOxygen) throws InterruptedException {
        hToO.take();
        hToO.take();
        releaseOxygen.run();
        oToH.put(1);
        oToH.put(1);
    }
}
```