### 解题思路
核心思路是在一个线程上锁，再另外一个线程解锁
首先想到的是LockSupport, 本地运行并没有问题，提交后连1都跑不过，无奈
然后换成信号量实现，ok过了
然后想着取下巧，使用volatile实现，没过，超时，但是u1s1，在本地测试中volatile是最快的（无奈）
想着可能是服务器分配资源的问题（自旋需要占用大量cpu时间），所以加上yield()，好了这次提交过了（但是本地测试加上yield后性能降低了，比locksupport有来有回）

所以结论就是：
1. 以后不要太在意解题网站给出的执行用时了orz
2. 为了研究这个效率问题花了一个小时时间搞到现在不睡觉的我是个傻逼！

如果觉得我有什么能改进的地方，请大佬们赐教

下面附上所有代码

### 代码

```java
/**
 * n = 100
 * LockSupport的实现连一个测试用例都不能通过，但是在测试中
 * 第一次运行最慢是15ms-12ms，预热后可以在7.6到9.2ms之间，效率比不上纯volatile，但是我觉得也可以接受
 * 主要是这个实现并不是取巧，而是有真正的线程挂起
 */
class FooBarLockSupport {
    private int n;
    private volatile Thread parking;

    public FooBarLockSupport(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        Thread ft = Thread.currentThread();
        for (int i = 0; i < n; i++) {
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            Thread p = parking;
            parking = ft;
            LockSupport.unpark(p);
            LockSupport.park();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        Thread bt = Thread.currentThread();
        parking = bt;
        for (int i = 0; i < n; i++) {
            LockSupport.park();
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            Thread p = parking;
            parking = bt;
            LockSupport.unpark(p);
        }
    }
}

/**
 * 虽然网页正常通过
 * 100次测试中
 * 但是在本机测试中效率是最低的，最慢15ms，最快也是快到10ms
 */
class FooBarSemaphore {
    private int n;

    private Semaphore semaphore = new Semaphore(1);
    private Semaphore semaphore2 = new Semaphore(0);


    public FooBarSemaphore(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            semaphore.acquire();
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            semaphore2.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while (semaphore.availablePermits()>0){}
            semaphore2.acquire();
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            semaphore.release();

        }
    }
}

/**
 * 这会超出时间限制，应该是因为自旋和volatile刷入主内存耗费的时间比较高?
 * 但是奇怪的是，每次在本机测试，这个方法效率都是可以的（而且次数越多越快）
 * 100次测试
 * 最慢12ms 最快5ms JIT会在多次运行的时候进行编译吗？
 * 在本地测试中，加了yield反而效率变低了，但是在服务器提交中，不加yield就会超时，应该是服务器资源问题，
 * 由此可见，做题目真的只是做题目，并不能代表真实情况
 */
class FooBarVolatile {
    private int n;

    volatile boolean fooRun = true;
    volatile boolean barRun = false;


    public FooBarVolatile(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while (barRun){
                //在本地测试中，加了yield反而效率变低了，但是在服务器提交中，不加yield就会超时
                Thread.yield();
            }
            barRun = true;
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            fooRun = false;
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while (fooRun){Thread.yield();}
            fooRun = true;
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            barRun = false;

        }
    }
}

```