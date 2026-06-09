### 解题思路
由于执行的时候要考虑内存及性能。那么最优解其实就是用最简单最原始的方式搞定它。
利用java object的wait以及notify完全可以实现两个线程通信
利用volatile关键字特性（基于MESI协议，线程间可见。）来保证线程的执行逻辑。


### 代码

```java
class FooBar {
    private int n;

    private Object lock = new Object();

    private volatile boolean f;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
                // printFoo.run() outputs "foo". Do not change or remove this line.
                synchronized (lock) {
                    if(f){
                        lock.wait();
                    }
                    printFoo.run();
                    f = true;
                    lock.notify();
                }

            
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
                synchronized(lock) {
                    // printBar.run() outputs "bar". Do not change or remove this line. 
                    if (!f) {
                        lock.wait();
                    }
        	        printBar.run();
                    f = false;
                    lock.notify();
                }
                
                
           
            
        }
    }
         
}
```