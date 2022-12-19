### 解题思路
此处撰写解题思路

### 代码
类 `CountDownLatch` 所提供的功能是判断 count 计数不为0时,则当前线程呈 wait 状态,也就是在屏障处等待
`second` 方法等待`first`方法执行后`count`-1 变为0,然后执行
`third`方法等待`second`方法执行后`count`-1 变为0 ,然后执行
```java
import java.util.concurrent.CountDownLatch;
class Foo {

    private CountDownLatch countDownLatchTwo = new CountDownLatch(1);
    private CountDownLatch countDownLatchThird = new CountDownLatch(1);
    
    public Foo() {

    }

    public void first(Runnable printFirst) throws InterruptedException {

        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        countDownLatchTwo.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {

        // printSecond.run() outputs "second". Do not change or remove this line.
        countDownLatchTwo.await();
        printSecond.run();
        countDownLatchThird.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {

        // printThird.run() outputs "third". Do not change or remove this line.
        countDownLatchThird.await();
        printThird.run();
    }
}
```