### 解题思路
此处撰写解题思路
目的：无论输入数字是什么顺序，无论线程执行顺序如何改变，都必须保证onetwothree的顺序。
实现：打印two的线程执行打印操作前必须等待打印one的线程执行打印操作，打印three的线程执行打印操作前必须等待打印two的线程执行完打印操作
解法1: 使用两个计数为1的CountDownLatch，使用first表示one打印操作，second表示two打印操作，one打印完成后释放first，two打印前等待one完成，打印后释放second，three打印前等待second释放
### 代码

```java
class Foo {
    CountDownLatch first = new CountDownLatch(1);
    CountDownLatch second = new CountDownLatch(1);
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        first.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        first.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        second.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        second.await();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```