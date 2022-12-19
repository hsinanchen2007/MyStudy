### 解题思路
CountDownLatch类，默认的构造函数为倒数的步长
步长为0则可以继续进行代码执行
等待倒计数的时候，使用await来hold

使用countDown方法来减少计数（向0靠拢）

### 代码

```java
class Foo {

    CountDownLatch latch1 = new CountDownLatch(1);
    CountDownLatch latch2 = new CountDownLatch(1);

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        latch1.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        try {
            latch1.await();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        latch2.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        try {
            latch2.await();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```