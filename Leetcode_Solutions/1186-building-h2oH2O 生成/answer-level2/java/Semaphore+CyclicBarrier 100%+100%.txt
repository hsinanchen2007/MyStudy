




    import java.util.concurrent.*;
    import java.util.concurrent.locks.*;
    class H2O {
        private Semaphore s1;
        private Semaphore s2;
        private CyclicBarrier c;
        public H2O() {
            s1 = new Semaphore(1);
            s2 = new Semaphore(2);
            c = new CyclicBarrier(3);
        }

        public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
	    	s2.acquire();
            // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            releaseHydrogen.run();
            try{
                c.await();
            }catch(Exception e){
            }
            s2.release();
        }

        public void oxygen(Runnable releaseOxygen) throws InterruptedException {
            s1.acquire();
            // releaseOxygen.run() outputs "H". Do not change or remove this line.
		releaseOxygen.run();
            try{
                c.await();
            }catch(Exception e){
            }
         s1.release();
        }
    }