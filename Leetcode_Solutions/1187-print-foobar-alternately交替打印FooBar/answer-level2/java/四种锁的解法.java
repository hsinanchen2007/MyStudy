#### 1. synchronized
```java
class FooBar {
    private int n;

    // 0 表示打印 foo
    // 1 表示打印 bar
    private int flag = 0;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            synchronized(this) {
                while (flag == 1) {
                    // 等待
                    this.wait();
                }
                // printFoo.run() outputs "foo". Do not change or remove this line.
        	    printFoo.run();
                flag = 1;
                this.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            synchronized(this) {
                while (flag == 0) {
                    // 等待
                    this.wait();
                }
                // printBar.run() outputs "bar". Do not change or remove this line.
        	    printBar.run();
                flag = 0;
                this.notifyAll();
            }  
        }
    }
}
```

#### 2. ReentrantLock
```java
class FooBar {
    private int n;

    // 0 表示打印 foo
    // 1 表示打印 bar
    private int flag = 0;

    private ReentrantLock lock = new ReentrantLock();
    private Condition fooPrintedCondition = lock.newCondition();
    private Condition barPrintedCondition = lock.newCondition();

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            try {
                lock.lock();
                while (flag == 1) {
                    // 等待打印 bar
                    barPrintedCondition.await();
                }
                // printFoo.run() outputs "foo". Do not change or remove this line.
        	    printFoo.run();
                flag = 1;
                // 通知 foo 打印完
                fooPrintedCondition.signalAll();
            } finally {
                lock.unlock();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            try {
                lock.lock();
                while (flag == 0) {
                    // 等待打印 foo
                    fooPrintedCondition.await();
                }
                // printBar.run() outputs "bar". Do not change or remove this line.
        	    printBar.run();
                flag = 0;
                // 通知 bar 打印完
                barPrintedCondition.signalAll();
            } finally {
                lock.unlock();
            }
        }
    }
}
```

#### 3. volatile 解法 (volatile write happens-before volatile read)
```java
class FooBar {
    private int n;

    // 0 表示打印 foo
    // 1 表示打印 bar
    private volatile int flag = 0;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
        	// printFoo.run() outputs "foo". Do not change or remove this line.
            while (flag != 0) {
                // Thread.yield()是让出当前线程的时间片
                // 从而避免空跑占用 cpu 资源
                Thread.yield();
            }
        	printFoo.run();
            flag = 1;
        
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while (flag != 1) {
                Thread.yield();
            }
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();

            flag = 0;
            
        }
    }
}
```

#### 4. CAS 乐观锁
```java
class FooBar {
    private int n;

    // 0 表示打印 foo
    // 1 表示打印 bar
    private AtomicInteger flag = new AtomicInteger(0);

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while (!flag.compareAndSet(0, 1)) {
                Thread.sleep(1);
            }
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
             
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while (!flag.compareAndSet(1, 0)) {
                Thread.sleep(1);
            }
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();

        }
    }
}
```