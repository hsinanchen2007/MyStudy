利用内置锁synchronized加上一个volatile变量,volatile变量用于标记当前执行的是哪个方法,从而决定是否要wait.
```
class FooBar {
    private int n;

    private final Object lock = new Object();
    private volatile boolean isFooTurn = true;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {

            // printFoo.run() outputs "foo". Do not change or remove this line.
            synchronized (this.lock) {
                if (!isFooTurn) {
                    this.lock.wait();
                }
                printFoo.run();
                this.isFooTurn = false;
                this.lock.notify();

            }


        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {

            // printBar.run() outputs "bar". Do not change or remove this line.
            synchronized (this.lock) {
                if (isFooTurn) {
                    this.lock.wait();
                }
                printBar.run();
                this.isFooTurn = true;
                this.lock.notify();
            }


        }
    }
}
```
