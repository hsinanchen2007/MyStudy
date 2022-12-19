### 解题思路
  CountDownLatch初始化指定一个数值，调用await方法，如果指定数值不为0则进入等待状态，知道数值为0
当frist执行时调用countDown将数值减1，依次类推
### 代码

```java
class Foo {
    private final CountDownLatch countDownLatch2;
    private final CountDownLatch countDownLatch3;
    public Foo() {
        countDownLatch2 = new CountDownLatch(1);
        countDownLatch3 = new CountDownLatch(1);
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        printFirst.run();
        countDownLatch2.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        countDownLatch2.await();
        printSecond.run();
        countDownLatch3.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        countDownLatch3.await();
        printThird.run();
    }
}
```