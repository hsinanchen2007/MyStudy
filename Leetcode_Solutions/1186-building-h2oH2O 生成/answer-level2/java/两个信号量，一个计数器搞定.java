
```
import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;
class H2O {

    public H2O() {
        
    }

    Semaphore h2 = new Semaphore(2);
    Semaphore o1 = new Semaphore(0);
    AtomicInteger hNum = new AtomicInteger(0);
    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		h2.acquire();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        if(hNum.incrementAndGet() == 2) {//获取两个H释放一个O
        	o1.release();
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        o1.acquire();
        // releaseOxygen.run() outputs "H". Do not change or remove this line.
		releaseOxygen.run();
		hNum.set(0);//释放一个O重置H计数
		h2.release(2);//释放两个H
    }
}
```
