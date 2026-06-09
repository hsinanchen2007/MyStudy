### 解题思路
此处撰写解题思路
  刚看到这个题就想着挺简单的啊，就是一个方法执行的时候另外一个方法不能执行这样的逻辑；那就挺随意啊，两个boolaen值不就行了，或者随便有值的就可以然后我首次提交的是这样的
```java
class Foo {

  private int i ;
  private int j;

  public Foo() {}

  public void first(Runnable printFirst) throws InterruptedException {

    // printFirst.run() outputs "first".
    printFirst.run();
    // mark the first job as done, by increasing its count.
    i++;
  }

  public void second(Runnable printSecond) throws InterruptedException {
 //这个是非常容易想不起来的那个怎么能让他一直读取数据知道有所改变
       while (i!= 1) {
      // waiting for the first job to be done.
    }
    // printSecond.run() outputs "second".
    printSecond.run();
    // mark the second as done, by increasing its count.
    j++
  }

  public void third(Runnable printThird) throws InterruptedException {
    while (j!= 1) {
      // waiting for the second job to be done.
    }
    // printThird.run() outputs "third".
    printThird.run();
  }
}
```
提交的时候通过了，证明我的思路是没有问题的，至少对于这个题来说是不用考虑i++时候线程不安全的问题的，然后就是官方的升级版；

### 代码

```java
class Foo {
//这个东西是针对 ++i 和 i++的时候都是线程不安全的
  private AtomicInteger firstJobDone = new AtomicInteger(0);
  private AtomicInteger secondJobDone = new AtomicInteger(0);

  public Foo() {}

  public void first(Runnable printFirst) throws InterruptedException {
    // printFirst.run() outputs "first".
    printFirst.run();
    // mark the first job as done, by increasing its count.
    firstJobDone.incrementAndGet();
  }

  public void second(Runnable printSecond) throws InterruptedException {
 //这个是非常容易想不起来的那个怎么能让他一直读取数据知道有所改变
       while (firstJobDone.get() != 1) {
      // waiting for the first job to be done.
    }
    // printSecond.run() outputs "second".
    printSecond.run();
    // mark the second as done, by increasing its count.
    secondJobDone.incrementAndGet();
  }

  public void third(Runnable printThird) throws InterruptedException {
    while (secondJobDone.get() != 1) {
      // waiting for the second job to be done.
    }
    // printThird.run() outputs "third".
    printThird.run();
  }
}
```