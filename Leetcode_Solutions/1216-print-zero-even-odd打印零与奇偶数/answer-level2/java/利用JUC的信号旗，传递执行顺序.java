### 解题思路
制定三个信号旗
分别释放即可，虽然复杂，但是逻辑还是比较清楚的

### 代码

```java
class ZeroEvenOdd {
    private int n;

    private Semaphore zeroLock;
    private Semaphore evenLock;
    private Semaphore oddLock;

    private AtomicInteger start;

    public ZeroEvenOdd(int n) {
        this.n = n;
        this.start = new AtomicInteger(0);
        zeroLock = new Semaphore(1);
        evenLock = new Semaphore(0);
        oddLock = new Semaphore(0);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        while (true) {
            zeroLock.acquireUninterruptibly();
            if (this.start.get() >= this.n) {
                evenLock.release(1);
                oddLock.release(1);
                return;
            }
            printNumber.accept(0);
            if ((this.start.get() + 1) % 2 == 0) {
                evenLock.release(1);
            } else {
                oddLock.release(1);
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        while (true) {
            evenLock.acquireUninterruptibly();
            if (this.start.incrementAndGet() > this.n) {
                return;
            }
            printNumber.accept(this.start.get());
            zeroLock.release(1);
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        while (true) {
            oddLock.acquireUninterruptibly();
            if (this.start.incrementAndGet() > this.n) {
                return;
            }
            printNumber.accept(this.start.get());
            zeroLock.release(1);
        }
    }
}
```