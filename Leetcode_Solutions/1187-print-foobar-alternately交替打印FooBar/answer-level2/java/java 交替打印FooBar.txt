
可以通过构造执行屏障来实现。设置两个标志位, 表示foo 方法 和 bar 方法是否执行完。  
比如：两个线程禁止锁的时候,只要另一个方法没执行完,当前方法就进行 wait 让出锁。


```
class FooBar {
    private int n;

    private boolean fooInvokeFinished = false;

    private boolean barInvokeFinished = true;

    private Object lock = new Object();

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	synchronized (lock) {
             while (!barInvokeFinished) {
                lock.wait();
             }
             printFoo.run();
             fooInvokeFinished = true;
             barInvokeFinished = false;
             lock.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            // printBar.run() outputs "bar". Do not change or remove this line.
        	synchronized (lock) {
                while (!fooInvokeFinished) {
                    lock.wait();
                }
            printBar.run();
            barInvokeFinished = true;
            fooInvokeFinished = false;
            lock.notifyAll();
            }
        }
    }
}
```
