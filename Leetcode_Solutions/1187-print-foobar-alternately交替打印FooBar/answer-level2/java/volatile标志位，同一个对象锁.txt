使用内存可见的flag标志，来决定谁被阻塞并释放锁，两个线程使用同一个lock对象就能控制同一时间只有一个线程进入自己的方法并打印，打印过就阻塞自己。

### 代码

```java
class FooBar {
    private int n;
    private volatile boolean  flag=true;
    private Object lock=new Object();
    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            synchronized(lock){
              if(!flag) lock.wait();
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            flag=false;
            lock.notifyAll();
            }

        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            synchronized(lock){
                if(flag) lock.wait();
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            flag=true;
            lock.notifyAll();
         }
        }

    }
}
```