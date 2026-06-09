### 解题思路
#### 使用synchronized同步静态对象lock，用原子布尔值保证foo()方法第一个执行
#### 在最后一个循环处不加上wait方法避免最后一个循环阻塞线程

### 代码

```java
class FooBar {
    private int n;

    static final Object lock = new Object();
    static AtomicBoolean isFooRun = new AtomicBoolean(true);

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        synchronized (lock) {
            for (int i = 0; i < n; i++) {
                // printFoo.run() outputs "foo". Do not change or remove this line.
                    if (isFooRun.get()) {
                        isFooRun.set(false);
                    }
                    lock.notify();
                    printFoo.run();
                    if (i != n - 1) {
                        lock.wait();
                    }
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        synchronized (lock) {
            for (int i = 0; i < n; i++) {
                // printBar.run() outputs "bar". Do not change or remove this line.
                    if (isFooRun.get()) {
                        lock.notify();
                        lock.wait();
                    }
                    lock.notify();
                    printBar.run();
                    if (i != n - 1) {
                        lock.wait();
                    }
            }
        }
    }
}
```