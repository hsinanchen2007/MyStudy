```java
class ZeroEvenOdd {
    private int n;
    Semaphore even, odd, zero;
    public ZeroEvenOdd(int n) {
        this.n = n;
        zero = new Semaphore(1);
        odd = new Semaphore(0);
        even = new Semaphore(0);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        boolean printOdd = true;
        for (int i = 0; i < n; i ++) {
            zero.acquire();
            printNumber.accept(0);
            if (printOdd) odd.release();
            else even.release();
            printOdd = ! printOdd;
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n / 2; i ++) {
            even.acquire();
            printNumber.accept(i * 2 + 2);
            zero.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        int times = n % 2 == 0 ? n / 2 : n / 2 + 1;
        for (int i = 0; i < times; i ++) {
            odd.acquire();
            printNumber.accept(i * 2 + 1);
            zero.release();
        }        
    }
}
```