### 解题思路
此处撰写解题思路

// 在first 和 second 方法里，必须先执行打印，再释放锁，否则 就会出现 被阻塞线程提前释放 打印出来的比本方法的打印早。
// 在 second 和 third方法里，必须先阻塞，防止提前打印

### 代码

```java
class Foo {

    private CountDownLatch secondLath;

    private CountDownLatch thirdLatch;

    public Foo() {
        secondLath = new CountDownLatch(1);
        thirdLatch = new CountDownLatch(1);

    }

    public void first(Runnable printFirst) throws InterruptedException {

        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        secondLath.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {

        secondLath.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        thirdLatch.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        thirdLatch.await();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```