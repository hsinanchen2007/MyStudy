class FooBar {
    private int n;
    private CyclicBarrier one = new CyclicBarrier(2);
    private CyclicBarrier two = new CyclicBarrier(2);

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        try{
            for (int i = 0; i < n; i++) {
            
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                one.await();
                two.await();
            }
        }catch(BrokenBarrierException e){

        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
         try{
            for (int i = 0; i < n; i++) {
            
                // printBar.run() outputs "bar". Do not change or remove this line.
                one.await();
                printBar.run();
                two.await();
            }
        }catch(BrokenBarrierException e){

        }
    }
}