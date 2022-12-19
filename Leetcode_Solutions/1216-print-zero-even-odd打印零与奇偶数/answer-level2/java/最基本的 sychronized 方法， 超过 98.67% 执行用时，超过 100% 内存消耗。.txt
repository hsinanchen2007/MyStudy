```
class ZeroEvenOdd {
    private int n;

    private Boolean flagOne = true;
    private Boolean flagTwo = true;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i=0; i<n; i++) {
            while (!flagOne || !flagTwo) {
                this.wait();
            }
            printNumber.accept(0);
            if(i%2 == 1)
                flagOne = false;
            if(i%2 == 0)
                flagTwo = false;
            this.notifyAll();

        }
    }

    public synchronized void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i=1; i<=n; i+=2) {
            while (!flagOne || flagTwo) {
                this.wait();
            }
            printNumber.accept(i);
            flagTwo = true;
            this.notifyAll();
        }
    }

    public synchronized void even(IntConsumer printNumber) throws InterruptedException {
        for(int i=2; i<=n; i+=2) {
            while (flagOne || !flagTwo) {
                this.wait();
            }
            printNumber.accept(i);
            flagOne = true;
            this.notifyAll();
        }
    }
}
```
