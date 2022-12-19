## 题解
解题思路为：
- 多线程并发访问同一个对象的成员方法
- 成员方法的执行顺序是固定的（突破点）

对于多线程固定顺序的执行，我们可以采用 Thread.join 方法。但此处不适用，此处我们只可以修改方法内部实现机制，并不能控制线程执行的方式，所以应该是线程等待唤醒机制。

顺序执行实现方案：
- 方法内部使用布尔变量控制当前方法是否可以执行，即 if(boolean)` 范式，某个方法执行后修改布尔值达到顺序控制
- 使用并发工具类 Semaphore 实现（初始许可为 0，执行前置条件后释放一个许可）

>  此处如果使用 `CyclicBarrier` 工具类不能保证 bar 在 foo 前执行，需要额外控制。

**方法内部使用布尔变量控制实现**

对于 synchronized 关键字，该实现添加在方法签名上而不是 for 循环内部，减少锁的操作，而是在获取锁后使用等待通知机制唤醒后继续执行。可参考博文-[Java 线程等待通知机制（wait、notify）](https://gourderwa.blog.csdn.net/article/details/103619528)

```java
class FooBar {
    private volatile boolean tmp = false;
    private int n;

    public FooBar(int n) {
        this.n = n;
    }

    public synchronized void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            if (tmp) {
                wait();
            }
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            tmp = true;
            notify();
        }
    }

    public synchronized void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            if (!tmp) {
                wait();
            }
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            tmp = false;
            notify();
        }
    }
}
```

## 参考
有关并发编程相关知识参考本博客专栏对应文章。