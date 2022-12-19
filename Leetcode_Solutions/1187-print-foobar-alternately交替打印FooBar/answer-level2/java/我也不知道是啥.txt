```java
class FooBar {
    private int n;
    private boolean isFooed;
    private Object lock;

    public FooBar(int n) {
        this.n = n;
        this.isFooed = false;
        this.lock = new Object();
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo.run() outputs "foo". Do not change or remove this line.
            synchronized(lock){
                while(isFooed){  
                    lock.wait();
                }
                printFoo.run();
                isFooed = true;
                lock.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            // printBar.run() outputs "bar". Do not change or remove this line.
            synchronized(lock){
                while(!isFooed){
                    lock.wait();
                }
                printBar.run();
                isFooed = false;
                lock.notifyAll();
            }	
        }
    }
}
```
