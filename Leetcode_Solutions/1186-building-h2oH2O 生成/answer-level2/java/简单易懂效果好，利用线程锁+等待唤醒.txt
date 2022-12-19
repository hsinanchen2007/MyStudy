```
class H2O {
    Integer num = 0;
    Object lock = null;
    
    public H2O() {
        lock = new Object();
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		synchronized (lock) {
            while (num % 3 == 0) {
                lock.wait();
            }
            // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            releaseHydrogen.run();
            num++;
            lock.notifyAll();
        }
        
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        synchronized (lock) {
            while (num % 3 != 0) {
                lock.wait();
            }
            // releaseOxygen.run() outputs "O". Do not change or remove this line.
            releaseOxygen.run();
            num++;
            lock.notifyAll();
        }
    }
}
```
