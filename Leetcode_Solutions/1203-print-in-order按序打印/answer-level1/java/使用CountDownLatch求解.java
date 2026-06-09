### 解题思路
CountdownLatch设置为1 当第一条线程完成后，countdown 去唤醒第二个， 第二个处理完成时，countdown去唤醒第三个

### 代码

```java
class Foo {
 private CountDownLatch second = new CountDownLatch(1);
    private CountDownLatch third = new CountDownLatch(1);
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        second.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
          second.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
           third.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
         third.await();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
``` 