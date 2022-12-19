```
import java.util.concurrent.*;

class ZeroEvenOdd {
    private int n;
    private Semaphore s,s1,s2;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
        s = new Semaphore(1);
        s1 = new Semaphore(0);
        s2 = new Semaphore(0);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i = 1;i <= n;i++) {
            s.acquire();
            printNumber.accept(0);
            if((i&1) == 0)
                s1.release();
            else
                s2.release();
        }

    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for(int i = 2;i <= n;i+=2) {
            s1.acquire();
            printNumber.accept(i);
            s.release();
        }

    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i = 1;i <= n;i+=2) {
            s2.acquire();
            printNumber.accept(i);
            s.release();
        }
    }
}
```
