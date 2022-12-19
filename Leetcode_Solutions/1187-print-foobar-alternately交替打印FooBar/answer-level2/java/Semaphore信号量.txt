### 解题思路
    通过信号量锁控制线程执行顺序，使之两个线程交替运行。

### 代码

```java
class FooBar {
    private int n;
    private Semaphore a,b;

    public FooBar(int n) {
        this.n = n;
        this.a = new Semaphore(1); // 保证foo先执行
        this.b = new Semaphore(0);
    }

     public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            a.acquire();
            printFoo.run();
            b.release();
        }
        
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            b.acquire();
            printBar.run();
            a.release();
        }
    }    
}
```