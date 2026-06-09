class FooBar {
    private int n;
    
    private Semaphore sp1,sp2;

    public FooBar(int n) {
        this.n = n;
        sp1 = new Semaphore(0);
        sp2 = new Semaphore(1);
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {    
            sp2.acquire();
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            sp1.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            sp1.acquire();
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            sp2.release();
        }
    }
}