
```

class FooBar {
    private int n;
    private Object lock;
    private Boolean printFooStatus;
    public FooBar(int n) {
        this.n = n;
        lock = new Object();
        printFooStatus = true;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
              synchronized (lock) {
                  //必须使用while
                  while (!printFooStatus){
                      lock.wait();
                  }
                  // printFoo.run() outputs "foo". Do not change or remove this line.
                  printFoo.run();
                  printFooStatus = false;
                   //必须放在synchronized里面
                  lock.notifyAll();
              }
        }
    }
    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            synchronized (lock) {
                //必须使用while
                while (printFooStatus) {
                    lock.wait();
                }
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                printFooStatus = true;
                //必须放在synchronized里面
                lock.notifyAll();
            }
        }
    }
}
```

这里需要注意的几个点：

1、初学者理解wait()的时候都认为是将当前线程阻塞，所以Thread.currentThread().wait();视乎很有道理。但是不知道大家有没有发现，在JDK类库中wait()和notify()方法并不是Thread类的，而是Object()中的。在其他线程调用此对象的 notify() 方法或 notifyAll() 方法前，当前线程等待

2、始终使用while循环来调用wait方法，永远不要在循环外调用wait方法，这样做的原因是尽管并不满足条件，但是由于其他线程调用notifyAll方法会导致被阻塞线程意外唤醒，此时执行条件不满足，它会导致约束失效

3、唤醒线程，应该使用notify还是notifyAll?notify会随机通知等待队列中的一个线程，而notifyAll会通知等待队列中所有线程，可知notify是有风险的 ，可能导致某些线程永远不会被通知到

4、当前线程必须拥有此对象监视器，然后才可以放弃对此监视器的所有权并等待 ，直到其他线程通过调用notify方法或notifyAll方法通知在此对象的监视器上等待的线程醒来,然后该线程将等到重新获得对监视器的所有权后才能继续执行。否则会报IllegalMonitorStateException 错误

作者BLOG：[www.liangsonghua.me](http://www.liangsonghua.me?utm_item=leetcode-cn)

作者介绍：京东资深工程师-梁松华，在稳定性保障、敏捷开发、JAVA高级、微服务架构方面有深入的理解
