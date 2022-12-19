
两个信号量分别用于限制可以进入的H,O数目
用了两个CyclicBarrier主要是为了保证reset能够在await之前进行
当secondStage.await()时候， firstStage.reset()
当firstStage.await()时候， secondStage.reset()
    CyclicBarrier firstStage = new CyclicBarrier(3);
    CyclicBarrier secondStage = new CyclicBarrier(3);

    Semaphore sem = new Semaphore(1);
    Semaphore h2 = new Semaphore(2);
    public H2O() {
        
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        h2.acquire();
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        try {
            firstStage.await();
            releaseHydrogen.run();
            secondStage.await();
        } catch (BrokenBarrierException e) {
            System.out.println(e);
        }
        h2.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
            sem.acquire();
            try {
                firstStage.await();
                firstStage.reset();
                releaseOxygen.run();
                secondStage.await();
                secondStage.reset();
            }catch (InterruptedException|BrokenBarrierException e) {
            }
            sem.release();
    }