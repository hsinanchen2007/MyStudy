class FooBar {
   private int n;

    private final Object mLock = new Object();
    private boolean mFlag = false;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            synchronized (mLock) {
                while (mFlag) {
                    mLock.wait();
                }
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                mFlag = true;
                mLock.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            synchronized (mLock) {
                while (!mFlag) {
                    mLock.wait();
                }

                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                mFlag = false;
                mLock.notifyAll();
            }
        }
    }
}