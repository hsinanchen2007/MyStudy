```
import java.util.concurrent.*;

class FooBar {
    private Semaphore s1,s2;
    private int n;

    public FooBar(int n) {
        this.n = n;
        s1 = new Semaphore(1);
        s2 = new Semaphore(0);
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            s1.acquire();
        	printFoo.run();
            s2.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            s2.acquire();
        	printBar.run();
            s1.release();
        }
    }
}
```
