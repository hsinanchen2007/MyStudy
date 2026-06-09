设m,n,最小公倍数为k，信号量初始化为k
H acquire release(k/m)
O acquire release(k/n)
    
    class H2O {
        private Semaphore semaphoreHydrogen = new Semaphore(2);//
        private Semaphore semaphoreOxygen = new Semaphore(2);
        public H2O() {
            
        }

        public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
            semaphoreHydrogen.acquire(1);
            // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            releaseHydrogen.run();
            semaphoreOxygen.release(1);
        }

        public void oxygen(Runnable releaseOxygen) throws InterruptedException {
            semaphoreOxygen.acquire(2);
            // releaseOxygen.run() outputs "O". Do not change or remove this line.
            releaseOxygen.run();
            semaphoreHydrogen.release(2);
        }
    }