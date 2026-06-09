经过多次比较，最终思路三执行用时最少，其次是思路二只使用CyclicBarrier,再其次是思路一使用信号量，最后可重入锁和无锁这两种思路虽然结果正确但是用时超时
### 思路一  信号量
  信号量的思路实现较为简单且信号量的计数器不会自动重置，每次调用acquire()默认信号量为1或者acquire(int num)方法后都会将信号当前信号量与acquire的信号量相减的值设置为新的信号量。
```java
class FooBar {
    private int n;

    public FooBar(int n) {
        this.n = n;
    }

    Semaphore fooSema = new Semaphore(1);
    Semaphore barSema = new Semaphore(0);

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            fooSema.acquire(); //触发打印foo线程得到执行，fooSema信号量大于0则方法返回，否则线程放入AQS等待队列（默认使用公平队列），还有acquire(int num)方法，此方法需要获取num个信号量
            printFoo.run();
            barSema.release();//barSema信号量值增加1,还可使用release(int num)方法，此方法会使得信号量增加num
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            barSema.acquire(); //barSema信号量大于0则方法立即返回，否则本线程放入AQS等待队列
            printBar.run();
            fooSema.release();
        }
    }
}
 ```
### 思路二  只使用CyclicBarrier
```java
class FooBar {
    private int n;

    public FooBar(int n) {
        this.n = n;
    }

    CyclicBarrier cb = new CyclicBarrier(2);//创建计数器值为2的屏障
    volatile boolean fooTurn = true;

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while(!fooTurn);  //不是打印foo线程的执行的次序
            try {
            printFoo.run();
            fooTurn = false;
		    cb.await(); //一个循环中打印foo线程完成，计数器值加1，计数器现在值为1，方法返回后线程进入等待执行队列
	    } catch (BrokenBarrierException e) {
	    }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            try {
		    cb.await(); //计数器值加1，现在计数器值为2，达到冲破屏障的条件，程序返回后可以往下执行
            printBar.run();
            fooTurn = true;
	    } catch (BrokenBarrierException e) {
	    }
            
        }
    }
}
```
### 思路三  CyclicBarrier和CounDownLatch结合
```java
import java.util.concurrent.CyclicBarrier;
class FooBar {
    private int n;
    private CyclicBarrier barrier;
    private CountDownLatch latch;
    public FooBar(int n) {
        this.n = n;
        barrier = new CyclicBarrier(2);
        latch = new CountDownLatch(1);
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	
            try{
                printFoo.run();
                latch.countDown();//触发printBar线程执行
                barrier.await();//等待printBar线程执行完成
            } catch(Exception e) {
                e.printStackTrace();
            }
            
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            // printBar.run() outputs "bar". Do not change or remove this line.
        	try {
            latch.await();//执行打印bar的触发条件，latch值减为0后此方法立即返回然后往下执行
            printBar.run();
            latch = new CountDownLatch(1);
            barrier.await(); //突破屏障，使得printFoo和printBar的线程得到执行
            } catch (Exception e) {
            }
            
        }
    }
}
```

### 思路四  使用公平锁

```java
class FooBar {
    private int n;

    public FooBar(int n) {
        this.n = n;
    }

    Lock lock = new ReentrantLock(true);
    volatile boolean fooTurn = true;

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; ) {
            lock.lock();
            try {
            	if(fooTurn) {
            	    printFoo.run();
                    i++;
                    fooTurn = false;
            	}
            }finally {
            	lock.unlock();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; ) {
            lock.lock();
            try {
            	if(!fooTurn) {
            	    printBar.run();
            	    i++;
            	    fooTurn = true;
            	}
            }finally {
            	lock.unlock();
            }
        }
    }
}
```
### 思路五  无锁
  无锁是线程自身不断自旋，没有其他方法那样有唤醒非执行状态的线程的途径，所以这种方法十分耗费资源，在执行了55个测试实例的时候就超时了，不可取，这里之所以写出来只是提供一种想法而已，在此题场景中并不可取。
``` java
class FooBar {
    private int n;

    public FooBar(int n) {
        this.n = n;
    }

    volatile boolean fooTurn = true;

    public void foo(Runnable printFoo) throws InterruptedException {     
        for (int i = 0; i < n; ) {
            if(fooTurn) {
        	printFoo.run();
            	i++;  //没有达到执行条件，线程状态不断自旋
            	fooTurn = false;
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {       
        for (int i = 0; i < n; ) {
            if(!fooTurn) {
        	printBar.run();
        	i++;
        	fooTurn = true;
            }
        }
    }
}
```

