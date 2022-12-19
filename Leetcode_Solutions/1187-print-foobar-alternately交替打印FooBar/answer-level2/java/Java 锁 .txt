### 方法一： 锁
#### 分析：
- 将`printFoo`操作和`printBar`操作分别加锁，来保证两者串行发生
- 设置一个`boolean`类型变量`fooTurn`来指明当前操作的轮次，当其为`True`时，打印`foo`,当其为`False`时，打印`bar`。
- 每个线程在同步代码块内部，判断当前轮次和自己的操作是否符合，若符合，则执行打印操作，若不符合，则放弃锁。

#### 实现：

```java []
class FooBar {
    private int n;
    private boolean fooTurn = true;
    private Object lock = new Object();
    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            synchronized(lock) {
                if (!fooTurn) lock.wait();
                fooTurn = false;
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                lock.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            synchronized(lock) {
                if (fooTurn) lock.wait();
                fooTurn = true;
                // printBar.run() outputs "bar". Do not change or remove this line.
        	    printBar.run();
                lock.notifyAll();
            }
        }
    }
}
```
