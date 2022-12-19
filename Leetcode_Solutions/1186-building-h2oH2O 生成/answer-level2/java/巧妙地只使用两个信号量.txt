### 解题思路
此题的关键的是如何保证一个O搭配两个HH，经过读题，发现结果虽然有很多种，但是我们可以取巧只得出OHHOHHOHH这种结果，因为信号量可以用来控制线程的先后执行顺序；这样我们的题目就变成了先让O线程执行再执行两次H线程；代码如下：

### 代码

```java
//这种方法只会输出OHHOHHOHH....这种顺序的结果，不过还是符合题目要求的，虽然耗时挺严重的
class H2O {
    private Semaphore sema_h;
    private Semaphore sema_o;
    public H2O() {
        sema_h = new Semaphore(0);//让H线程后执行
        sema_o = new Semaphore(2);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        
        sema_h.acquire();//等待H线程的信号量大于0
        releaseHydrogen.run();
        sema_o.release();//释放1个O线程的信号量，当sema_o的值达到2时下一波的O线程就可以开始执行了
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        sema_o.acquire(2);//初始值大于0且sema_h的初始值为0，导致O线程优先执行
		releaseOxygen.run();
        sema_h.release(2);//释放2个sema_h信号量，意味着接下来H线程能执行并且要执行两个
    }
}
```