
## 题解
解题思路为：
- 多线程并发访问同一个对象的成员方法
- 成员方法的执行顺序是存在一定规律（三个线程之间的规律！突破点）

顺序执行实现方案：
- 同步等待通知机制。方法内部使用布尔变量控制当前方法是否可以执行，即 `while(boolean)` 范式，某个方法执行后修改布尔值达到顺序控制
- 同步等待通知机制可以实现的 Lock 可以实现（感兴趣可以尝试）
- 使用并发工具类 Semaphore 实现（初始许可为 0 可以让方法延迟执行，执行前置条件后释放对应许可）

### 解法：同步等待通知机制
该解法平台报超出时间限制！本地测试通过。

针对该解法，可以把 wait&notifyAll 舍弃，直接采用无锁方式实现，根据条件判断一直轮询（方法耗时较长时 CPU 占用较高）。
```java
class ZeroEvenOdd {
    private volatile int flag = 0;
    private int n;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void zero(IntConsumer printNumber) throws InterruptedException {
        while (true) {
            if (flag > 0) {
                wait();
            }
            flag = -flag + 1;
            if (flag > n) {
                break;
            }
            printNumber.accept(0);
            notifyAll();
        }
    }

    // 偶数
    public synchronized void even(IntConsumer printNumber) throws InterruptedException {
        while (true) {
            while (flag <= 0 || (flag & 1) == 1) {
                wait();
            }
            if (flag > n) {
                break;
            }
            printNumber.accept(flag);
            flag = -flag;
            notifyAll();
        }
    }

    // 奇数
    public synchronized void odd(IntConsumer printNumber) throws InterruptedException {
        while (true) {
            while (flag <= 0 || (flag & 1) == 0) {
                wait();
            }
            if (flag > n) {
                break;
            }
            printNumber.accept(flag);
            flag = -flag;
            notifyAll();
        }
    }
}
```

### 解法：信号量 Semaphore 控制
```java
class ZeroEvenOdd {
    private final Semaphore z = new Semaphore(1);
    private final Semaphore o = new Semaphore(0);
    private final Semaphore e = new Semaphore(0);

    private int n;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            z.acquire();
            printNumber.accept(0);
            if ((i & 1) == 0) { // 偶数判断
                o.release();
            } else {
                e.release();
            }
        }
    }

    // 偶数
    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            e.acquire();
            printNumber.accept(i);
            z.release();
        }
    }

    // 奇数
    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            o.acquire();
            printNumber.accept(i);
            z.release();
        }
    }
}
```
## 参考

- 参考博文-[Java 线程等待通知机制（wait、notify）](https://gourderwa.blog.csdn.net/article/details/103619528)
- 参考博文-[Java 控制并发数的信号量-Semaphore](https://gourderwa.blog.csdn.net/article/details/103726711)
- 本题在 [LeetCode-1114. 按序打印（多线程）](https://gourderwa.blog.csdn.net/article/details/104162586) 顺序执行基础上增加了 for 循环内部等待通知操作。
- 更多并发编程相关博文参考 [Java 并发编程-专栏文章目录汇总 ](https://blog.csdn.net/xiaohulunb/article/details/103594468)