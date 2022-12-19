### 解题思路
1. 使用信号量Semaphore类
2. 初始化foo相关的“许可”初始化为1个，bar相关的许可初始化为0个
3. 在foo中先执行，执行完毕后，给bar的许可增加1个（通过调用信号量的release）方法
4. 在bar中后执行，执行完毕后，给foo的许可增加1个
5. 整个执行到n个即可

### 代码

```java
class FooBar {
    private int n;

    public FooBar(int n) {
        this.n = n;
    }

    Semaphore foolock = new Semaphore(1);
    Semaphore barlock = new Semaphore(0);

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            foolock.acquireUninterruptibly();
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            barlock.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            barlock.acquireUninterruptibly();
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            foolock.release();
        }
    }
}
```