### 解题思路
此处撰写解题思路
使用2个CDL类，分别在2、3线程使用线程等待。
感觉使用volatile速度要更快一些，毕竟只用了一个变量。
### 代码

```java
class Foo {
    CountDownLatch c = new CountDownLatch(1);
CountDownLatch c2 = new CountDownLatch(1);
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
      
       
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        c.countDown();
        
    }

    public void second(Runnable printSecond) throws InterruptedException {
       c.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
       c2.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
       c2.await();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
```