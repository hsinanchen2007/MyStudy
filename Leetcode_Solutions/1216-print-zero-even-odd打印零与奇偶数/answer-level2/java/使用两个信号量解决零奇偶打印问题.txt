### 解题思路
![微信截图_20200131190821.png](https://pic.leetcode-cn.com/590cb00e7ba172ba9408cf2dbb00b730424da1b45eed6b8673de3738faa85c41-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200131190821.png)

与上题思路类似，关键是判断零、奇数和偶数的顺序关系，来决定信号量的获取和释放的顺序
需要注意的是，这里需要在while循环等待获取当前线程的锁时，使用Thread.yiels()让出时间片，否则会报错超时（测试执行没有问题）。

### 代码

```java
class ZeroEvenOdd {
    private int n;

    private Semaphore zero = new Semaphore(1);
    
    private Semaphore evenOdd = new Semaphore(1);

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while (zero.availablePermits() == 0) {
                Thread.yield();
            }
            printNumber.accept(0);
            zero.acquire();
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            while (evenOdd.availablePermits() == 1 || zero.availablePermits() == 1) {
                Thread.yield();
            }
            printNumber.accept(i);
            zero.release();
            evenOdd.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            while (evenOdd.availablePermits() == 0 || zero.availablePermits() == 1) {
                Thread.yield();
            }
            printNumber.accept(i);
            zero.release();
            evenOdd.acquire();
        }
    }
    
}
```