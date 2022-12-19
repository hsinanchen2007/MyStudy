class H2O {
    private volatile int hCount = 0;
    public H2O() {
        
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        while(hCount == 2){
            Thread.yield();
        }

        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        hCount++;
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        while(hCount != 2){
            Thread.yield();
        }
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
		releaseOxygen.run();
        hCount = 0;
    }
}