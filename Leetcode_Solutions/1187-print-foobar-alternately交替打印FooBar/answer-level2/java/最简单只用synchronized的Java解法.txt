### 解题思路
synchronized 解决单次执行， volatile boolean 解决第一次执行

### 代码

```java
class FooBar {

    private int              n;
    private volatile boolean isFoo;

    public FooBar(int n) {
        this.n = n;
    }

    public synchronized void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            //            synchronized (lock) {
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            isFoo = true;
            this.notify();
            if (i < n - 1) {
                this.wait();
            }
            //            }
        }
    }

    public synchronized void bar(Runnable printBar) throws InterruptedException {
        if (!isFoo) {
            this.wait();
        }
        for (int i = 0; i < n; i++) {
            //            synchronized (lock) {
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            this.notify();
            if (i < n - 1) {
                this.wait();
            }
            //            }
        }
    }
}
```