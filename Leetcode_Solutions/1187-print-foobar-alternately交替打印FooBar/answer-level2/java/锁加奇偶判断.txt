规律：当i从0开始计数时， foo在i为偶数打印， bar在i为奇数时打印。

```java
class FooBar {
    int n;
    int i = 0;
    Object lock = new Object();
    public FooBar(int n) {
        this.n = n*2;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        while(i < n-1) {
            // printFoo.run() outputs "foo". Do not change or remove this line.
        	synchronized (lock) {
                if (i % 2 != 0) {
                    lock.wait();
                } 
                printFoo.run();
                i++;
                lock.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        while(i < n) {
            synchronized (lock) {
                if (i % 2 != 1) {
                    lock.wait();
                }
                // printBar.run() outputs "bar". Do not change or remove this line.
        	    printBar.run();
                i++;
                lock.notifyAll();
            }
        }
    }
}
```