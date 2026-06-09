class H2O {

   private final Object mLock = new Object();

    private int mFlag = 0;

    public H2O() {

    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        synchronized (mLock) {
            while ((mFlag %= 5) == 2) {
                mLock.wait();
            }
            mFlag += 1;
            // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            releaseHydrogen.run();
            mLock.notifyAll();
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        synchronized (mLock) {
            while ((mFlag %= 5) >= 3) {
                mLock.wait();
            }
            mFlag += 3;
            // releaseOxygen.run() outputs "O". Do not change or remove this line.
            releaseOxygen.run();
            mLock.notifyAll();
        }
    }
}