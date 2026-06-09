public class H20 {
    //屏障 等待一组线程到达一个屏障点
    private CyclicBarrier hBarrier, oBarrier;
    private Lock lock = new ReentrantLock(false);
    private Condition hCondition, oCondition;
    //通知标识
    private static volatile boolean flag = false;

    public H20() {
        hBarrier = new CyclicBarrier(2);
        oBarrier = new CyclicBarrier(1);
        hCondition = lock.newCondition();
        oCondition = lock.newCondition();
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException, BrokenBarrierException {
        //等待2个H线程到达这里
        hBarrier.await();
        System.out.println("2 个H线程到达执行下面操作:");
        releaseHydrogen.run();
        //等待O元素到达
        while (!flag) {
            hCondition.await();
        }
        //重置屏障
        hBarrier.reset();
        flag = true;
        oCondition.signal();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException, BrokenBarrierException {
        //等待O线程到达这里
        oBarrier.await();
        System.out.println("1 个O线程到达执行下面操作:");
        releaseOxygen.run();
        while (!flag) {
            oCondition.await();
        }
        //重置屏障
        oBarrier.reset();
        //唤醒H线程
        hCondition.signal();
    }
}