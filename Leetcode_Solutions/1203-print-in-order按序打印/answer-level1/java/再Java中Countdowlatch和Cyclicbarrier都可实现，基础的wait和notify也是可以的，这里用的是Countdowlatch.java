### 解题思路
countDownLatch可以使使一个线程等待其他线程各自执行完毕后再执行，原理就是在同步的代码块之前加锁latch.await(),在其他线程中第这个latch清零后才会继续执行await之后的操作。
本题为三个线程，这里用了两个计数器，第一个线程执行之后第一个latch和第二个latch都减1，这样latchA清零，线程2可以继续执行，执行结束后对第二个计数器再减1，这样第二个计数器也清零了，第三个线程就可以继续执行了

### 代码

```java
class Foo {

    private final CountDownLatch latchB = new CountDownLatch(1);
    private final CountDownLatch latchC = new CountDownLatch(2);
    public Foo() {
    
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        latchB.countDown();
        latchC.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        latchB.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        latchC.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        latchC.await();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```