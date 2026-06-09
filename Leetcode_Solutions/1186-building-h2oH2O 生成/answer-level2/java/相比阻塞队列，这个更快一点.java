```java
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.ReentrantLock;

class H2O {
    
    AtomicInteger hEvent = new AtomicInteger();
    AtomicInteger oEvent = new AtomicInteger();
    ReentrantLock hLock = new ReentrantLock();

    AtomicInteger count = new AtomicInteger();
    
    public H2O() {

    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hLock.lock();
        int num = count.incrementAndGet();
        if(num%2 == 1) {//序号为奇数的 H 线程，打印并释放锁后，直接返回
            releaseHydrogen.run();
            hLock.unlock();
            return;
        }
        releaseHydrogen.run();

        //只有序号为偶数的 H 线程与 O 线程通信
        hEvent.set(1);
        for(;!oEvent.compareAndSet(1,0);){}
        hLock.unlock();
    }

    public synchronized void oxygen(Runnable releaseOxygen) throws InterruptedException {
        for (;!hEvent.compareAndSet(1,0);){}
        releaseOxygen.run();
        oEvent.set(1);
    }
}
```