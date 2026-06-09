zero先打印，用第一个Barrier然后唤醒其他线程干活，
用第二个Barrier带大家进入下一个循环


class ZeroEvenOdd {
    private int n;
    final CyclicBarrier cycli = new CyclicBarrier(3);
    final CyclicBarrier second = new CyclicBarrier(3);
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i <= n; i ++) {
            printNumber.accept(0);
            try{
                cycli.await();
                second.await();
            }catch(BrokenBarrierException e) {

            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
            for(int i=1;i <= n; i ++) {
                try{
                    cycli.await();
                    if( i>0 && i%2 ==0)
                        printNumber.accept(i);
                    second.await();
                }catch(BrokenBarrierException e) {

                }
            }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
            for(int i=1;i <= n; i ++) {
                try{
                    cycli.await();
                    if( i%2 !=0)
                        printNumber.accept(i);
                    second.await();
                }catch(BrokenBarrierException e) {

                }
            }
    }
}