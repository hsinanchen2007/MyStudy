class FooBar {
    private int n;
    public Object o = new Object();
    public volatile int count = 0;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	synchronized(o){
               while(count!=0){
                   o.wait();
               }
 
                printFoo.run();
                count = 1;
                o.notify();
                
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            // printBar.run() outputs "bar". Do not change or remove this line.
        	    synchronized(o){
                while(count!=1){
                    o.wait();
                }
                printBar.run();
                count = 0 ;
                o.notify(); 
            
                }
        }
    }
}