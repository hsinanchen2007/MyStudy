时间：95%，内存：100%

```java
class ZeroEvenOdd {
    private int n;
    private int i = 1;
    private boolean isZeroPrinted = false;
    private Object lock = new Object();

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        while (i < n + 1) {
            synchronized (lock) {
                if (isZeroPrinted) {
                    lock.wait();
                } else {
                    printNumber.accept(0);
                    isZeroPrinted = true;
                    lock.notifyAll();
                }
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        while (i < n + 1) {
            synchronized (lock) {
                if (!isZeroPrinted || i % 2 != 0) {
                    lock.wait();
                } else {
                    printNumber.accept(i++);
                    isZeroPrinted = false;
                    lock.notifyAll();
                }
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        while (i < n + 1) {
            synchronized (lock) {
                if (!isZeroPrinted || i % 2 == 0) {
                    lock.wait();
                } else {
                    printNumber.accept(i++);
                    isZeroPrinted = false;
                    lock.notifyAll();
                }
            }
        }
    }
}
```