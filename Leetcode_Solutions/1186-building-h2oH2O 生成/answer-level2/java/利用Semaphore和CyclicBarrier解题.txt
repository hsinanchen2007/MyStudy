这个代码应该没毛病啊，11条测试用例 有一条没通过，哪位老铁帮忙看看？

```cs
import java.util.concurrent.*;
import java.util.concurrent.locks.*;


class H2O {
    private Semaphore hydrogenSemaphore = new Semaphore(2);
    private Semaphore oxygenSemaphore = new Semaphore(1);
    private CyclicBarrier barrier = new CyclicBarrier(3,new Runnable(){
        public void run(){
            hydrogenSemaphore.release(2);
            oxygenSemaphore.release();
        }
    });
    public H2O() {
        
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        System.out.println("hydrogen ---");
		hydrogenSemaphore.acquire();
        
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        try{
            barrier.await();
        }catch(BrokenBarrierException ex){
            
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
                System.out.println("oxygen ---");


        oxygenSemaphore.acquire();
        // releaseOxygen.run() outputs "H". Do not change or remove this line.
		releaseOxygen.run();
        try{
            barrier.await();
        }catch(BrokenBarrierException ex){
            
        }
                
    }
}
```