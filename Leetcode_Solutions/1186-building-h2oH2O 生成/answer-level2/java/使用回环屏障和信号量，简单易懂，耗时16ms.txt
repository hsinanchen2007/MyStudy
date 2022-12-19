### 思路

利用回环屏障的特性循环执行一个O线程和2个H线程。
```java
class H2O {
    private CyclicBarrier barrier;
    private Semaphore sema_h;
    private Semaphore sema_o;
    public H2O() {
        barrier = new CyclicBarrier(3);//达到3个线程放开屏障
        sema_h = new Semaphore(2);
        sema_o = new Semaphore(1);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        try {
        sema_h.acquire();//sema_h的值减1并直接返回，若是sema_h为0，再次减1时sema_h会小于0，此时本线程会阻塞在这里，这就保证了一个批次中必须有两个H线程
        barrier.await();//执行一次屏障的值减1，若是值大于0则线程会阻塞在这里，这就保证了一个批次有3个线程
        releaseHydrogen.run();
        sema_h.release();//释放1个H线程的信号量
        } catch(Exception e) {

        }
        
        
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        try {
        sema_o.acquire();//sema_o的值减1，若是sema_o减1之后小于0，则线程阻塞在这里，这就保证了一个批次中只有一个O线程
        barrier.await();//是否达到屏障点，达到则往下执行，否则阻塞在此处
		releaseOxygen.run();
        sema_o.release();
        } catch (Exception e) {

        }
        
    }
}
```