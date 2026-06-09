### 解题思路
此处撰写解题思路

之前利用wait notifyAll的行不通，因为开启LeetCode同时间测试多个样例的时候，多个线程，相互影响了，notify 不具有定向。

然后考虑 用 condition ，因为condition 可以指定wait 和 notify 。每个对象一个condition 就会不会相互影响。

但是最大影响是，先启动，不一定先执行，要保证，2个线程都启动了，而且要保证 notif 和 wait的顺序，可能出现 notify在 wait前面了，就会出现超时的情况。


再次利用LockSupport, 最大的特性可以定向唤醒线程。且在线程启动的情况下，提前sinal，也是可以的。这样就避免的先后调用的问题。利用countdown 保证先后线程的启动。再次利用LockSupport 避免先后的问题。

```bash
29 分钟前	超出时间限制	N/A	N/A	Java
30 分钟前	超出时间限制	N/A	N/A	Java
33 分钟前	超出时间限制	N/A	N/A	Java
1 小时前	超出时间限制	N/A	N/A	Java
1 小时前	超出时间限制	N/A	N/A	Java
1 小时前	超出时间限制	N/A	N/A	Java
1 小时前	超出时间限制	N/A	N/A	Java
1 小时前	超出时间限制	N/A	N/A	Java
````


### 代码

```java
class FooBar {
    private int n;
    private volatile Thread t1, t2;
    private CountDownLatch latch = new CountDownLatch(1);
    private CountDownLatch latch2 = new CountDownLatch(1);

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        t1 = Thread.currentThread();
        latch.countDown();
        latch2.await();

        for (int i = 0; i < n; i++) {
            printFoo.run();
            LockSupport.unpark(t2);
            LockSupport.park();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        t2 = Thread.currentThread();
        latch.await();
        latch2.countDown();


        for (int i = 0; i < n; i++) {
            LockSupport.park();

            printBar.run();

            LockSupport.unpark(t1);
        }
    }
}
```