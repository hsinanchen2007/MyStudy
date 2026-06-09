### 1 简介
#### 1.1 CountDownLatch与CyclicBarrier的区别
    CounDownLatch和CyclicBarrier均适合用于主线程中开启多个线程区执行任务并且主线程需要等待所有子线程执行完毕之后再汇总的情景；现在做个不是很恰当的比喻，一个水库有多个水源可进行注水，多个水源注水完毕后，水位线达到了必须放水的程度的时候，CountDownLatch是被水冲垮的堤坝，虽然水被放出去了，但是堤坝已经不能再用了，除非重新修建堤坝；而CyclicBarrier相当于可打开和关闭的水闸，各水源注水完毕达到放水条件后打开的水闸，放水后水闸关闭，再次等待水位线达到放水条件，水闸是可循环使用的。   
##### 1.2 思路
    CounDownLatch用于保证一个循环内线程执行的先后顺序，CyclicBarrier用于循环前一个过程；在一次循环中foo要比bar先打印出来并且打印foo的线程还要等待打印bar的线程完成后才能开始下一次打印foo。
### 代码

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
            latch.await();//触发条件
            printBar.run();
            latch = new CountDownLatch(1);
            barrier.await(); //触发printFoo和printBar的线程得到执行
            } catch (Exception e) {
            }
            
        }
    }
}
```