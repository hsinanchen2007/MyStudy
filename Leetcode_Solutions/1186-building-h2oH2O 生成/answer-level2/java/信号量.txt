class H2O {

    private Semaphore hs;
    private Semaphore os;
    public H2O() {
        hs = new Semaphore(2);
        os = new Semaphore(2);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        hs.acquire();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        os.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        os.acquire(2);
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
		releaseOxygen.run();
        hs.release(2);
    }
}