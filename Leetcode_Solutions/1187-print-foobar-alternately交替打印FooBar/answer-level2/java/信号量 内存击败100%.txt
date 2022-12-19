使用信号量
acquire  就是 值+1
release  就是 值-1
_简单理解就是当值是0，就可以继续执行，不为零就等待变为0后再执行_

``` java
public class FooBar {
    private int n;
    //here is the full path, or maybe cann't compile in leetcode.
    java.util.concurrent.Semaphore semaphoreFoo=new java.util.concurrent.Semaphore(0);
    java.util.concurrent.Semaphore semaphoreBar=new java.util.concurrent.Semaphore(0);

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            printFoo.run();
            //由于下面阻塞了，所以这里变为0，下面的方法就能继续执行
            semaphoreBar.release();
            //这里让他等一会，等到bar()执行完
            semaphoreFoo.acquire();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            // 进来先变为1，就会等上面的release()使他变为0，才进行，所以肯定在foo之后。
            semaphoreBar.acquire();
            printBar.run();
            //bar()执行完了，就让foo()继续。
            semaphoreFoo.release();
        }
    }
}
```