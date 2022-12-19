### 解题思路
当countDown为0时，放行。
### 代码

```java
class Foo {
    private CountDownLatch latch = new CountDownLatch(1);
    private CountDownLatch latch1 = new CountDownLatch(1);    
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        latch.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        latch.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        latch1.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        latch1.await();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```