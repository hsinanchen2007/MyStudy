如果传入的氢氧比例不平衡，并且时间过长的话，估计会抛出异常，应该用acquireUninterruptibly好一点
import java.util.concurrent.*;
class H2O {
    private Semaphore sOxygen ,sHydrogen;
    public H2O() {
        sOxygen = new Semaphore(2);
        sHydrogen = new Semaphore(2);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        sHydrogen.acquire(1);
        releaseHydrogen.run();
        sOxygen.release(1); 
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        sOxygen.acquire(2);
        // releaseOxygen.run() outputs "H". Do not change or remove this line.
		releaseOxygen.run();
        sHydrogen.release(2); 
    }
}