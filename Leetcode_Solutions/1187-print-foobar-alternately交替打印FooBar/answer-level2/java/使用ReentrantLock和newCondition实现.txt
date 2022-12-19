### 解题思路
类似于生产消费者模型，使用ReentrantLock代替synchronized实现。

### 代码

```java
class FooBar {
    private int n;
    private final ReentrantLock lock;
    private final Condition condition;
    private volatile boolean fooRun = false;
    public FooBar(int n) {
        this.n = n;
        lock = new ReentrantLock();
        condition = lock.newCondition();
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        lock.lock();
        for (int i = 0; i < n; i++) {
            while(fooRun){
                //foo已经执行，bar没有执行需要等待
                condition.await();
            }
        	printFoo.run();
            fooRun=true;
            condition.signal();
        }
        lock.unlock();
    }

    public void bar(Runnable printBar) throws InterruptedException {
        lock.lock();
        for (int i = 0; i < n; i++) {
            while(!fooRun){
                //foo没有执行需要等待
                condition.await();
            }
                
        	printBar.run();
            fooRun=false;
            condition.signal();
        }
        lock.unlock();
    }
}
```