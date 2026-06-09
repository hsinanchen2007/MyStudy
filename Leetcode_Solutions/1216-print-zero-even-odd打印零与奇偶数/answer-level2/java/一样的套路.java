public class ZeroEvenOdd {
    private int n;

    private int i;
    private boolean mFlag = true;
    private final Object mLock = new Object();

    public ZeroEvenOdd(int n) {
        this.n = n;
        i = 0;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        synchronized (mLock) {
            for (; i < n; ) {
                while (!mFlag) {
                    mLock.wait();
                }
                mFlag = false;
                i++;
                printNumber.accept(0);
                mLock.notifyAll();
            }
        }

    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        synchronized (mLock) {
            for (; i < n + 1; ) {
                while (mFlag || i % 2 != 0) {
                    mLock.wait();
                }
                if (i <= n) {
                    printNumber.accept(i);
                }
                if (i < n) {
                    mFlag = true;
                } else {
                    i++;
                }
                mLock.notifyAll();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        synchronized (mLock) {
            for (; i < n + 1; ) {
                while (mFlag || i % 2 == 0) {
                    mLock.wait();
                }
                if (i <= n) {
                    printNumber.accept(i);
                }
                if (i < n) {
                    mFlag = true;
                } else {
                    i++;
                }
                mLock.notifyAll();
            }
        }
    }

}