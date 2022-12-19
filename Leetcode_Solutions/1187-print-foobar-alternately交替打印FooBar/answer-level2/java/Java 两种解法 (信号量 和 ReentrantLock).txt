### 方法一 使用信号量

使用信号量的方式比较简洁, 设定两个信号量即可.

```Java
class FooBar {
    private int n;
    private final Semaphore fooSem;
    private final Semaphore barSem;

    public FooBar(int n) {
        this.n = n;
        this.fooSem = new Semaphore(1);
        this.barSem = new Semaphore(0);
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            fooSem.acquire();
            printFoo.run();
            barSem.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            barSem.acquire();
            printBar.run();
            fooSem.release();
        }
    }
}
```

### 方法二 加锁 使用计数器

使用一个计数器 `cnt` 表示当前该谁来打印. 在调用 `printXXX()` 之前检查计数器的值:

- 当 `cnt` 为 0 时才能调用 `printFoo()`, 调用后设置 `cnt` 为 1
- 当 `cnt` 为 1 时才能调用 `printBar()`, 调用后设置 `cnt` 为 0

如果 `cnt` 不是当前的值, 就需要等待. 如果只使用一个简单的 `while` 循环: `while (cnt != 0);`, 会超时, 可以使用 `synchronized` + `wait()` + `notifyAll()` 来提速. *`wait()` 之后就不会无脑地一直循环了, 而是等待被 `notify`, 所以更快.*

而相比于 `synchronized`, 使用 `ReentrantLock` + `Condition` 更快. 思路一样, 写法略有不同.

#### 使用 `synchronized`

```Java
class FooBar {
    private int n;
    private volatile int cnt;
    private final Object lock;

    public FooBar(int n) {
        this.n = n;
        this.cnt = 0;
        this.lock = new Object();
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            synchronized (lock) {
                while (cnt != 0) {  // 因为只有两个, 所以写 if 也可以
                    lock.wait();
                }
                printFoo.run();
                cnt = 1;
                lock.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            synchronized (lock) {
                while (cnt != 1) {
                    lock.wait();
                }
                printBar.run();
                cnt = 0;
                lock.notifyAll();
            }
        }
    }
}
```

#### `ReenTrantLock` 速度较快

```java
class FooBar {
    private int n;
    private volatile int cnt;
    private final Lock lock;
    private final Condition condition;

    public FooBar(int n) {
        this.n = n;
        this.cnt = 0;
        this.lock = new ReentrantLock();
        this.condition = this.lock.newCondition();
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            lock.lock();
            try {
                while (cnt != 0) {
                    condition.await();
                }
                printFoo.run();
                cnt = 1;
                condition.signalAll();
            } finally {
                lock.unlock();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            lock.lock();
            try {
                while (cnt != 1) {
                    condition.await();
                }
                printBar.run();
                cnt = 0;
                condition.signalAll();
            } finally {
                lock.unlock();
            }
        }
    }
}
```