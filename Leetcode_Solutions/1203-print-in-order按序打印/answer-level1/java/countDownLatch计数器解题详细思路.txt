### 解题思路
countDownLatch这个类使一个线程等待其他线程各自执行完毕后再执行。是通过一个计数器来实现的，计数器的初始值是线程的数量。每当一个线程执行完毕后，计数器的值就-1，当计数器的值为0时，表示所有线程都执行完毕，然后在闭锁上等待的线程就可以恢复工作了。

1:首先考虑使用一个线程安全的线程标记，选择了countDownLatch计数器。
2:根据题目描述就是在线程1,2,3不论谁先执行，都要使执行结果为first - second - third
3:分析countDownLatch计数器，他的作用就是初始化一个计数器数值指定，只有在该计数器的值为0时才继续执行。
  1、我们先创建两个计数器 c2 是second的，c3是third 初始化都为1.
  2、我们可以使用它的.countDown（解释：使当前计数器减一）方法在first执行后将c2的计数器置为0，在c2执行      后通过.countDown方法将c3的计数器置为0。
  3、同时在应对如果 second、third先执行，在他们之中.await（解释：如果当前计数器不为0，那么挂起，等待       计数器为0后继续执行）自己的计数器。
4：问题解决。

### 代码

```java
class Foo {
    private CountDownLatch c2;
    private CountDownLatch c3;
    public Foo() {
         c2 = new CountDownLatch(1);
         c3 = new CountDownLatch(1);
    }
    
    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        c2.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        c2.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        c3.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        c3.await();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```