### 解题思路
此处撰写解题思路

### 代码

```java
class ZeroEvenOdd {
    private int n;

    /**
     * 思路：
     * 使用三个 Condition条件变量来使三个线程根据条件进行等待或者执行
     *
     * 这里有三个线程，如果三个线程相互协调 最起码需要两个条件 也就是下面的两个变量 blockZero和blockEven
     *
     * 输出0 和 输出非0 的线程  共同使用blockZero来协调
     * 输出奇数和偶数的线程 使用blockEven来协调
     *
     * 输出0的线程执行后，需要唤醒奇数或者偶数线程，题目要求一定会有n个0输出，第一个0输出后输出奇数，第二个0输出后输出偶数
     * 然后我们就可以根据当前输出的0的次数是奇数还是偶数来判断唤醒奇数还是偶数线程
     * 而无论是奇数还是偶数线程执行过后，都一定要唤醒0线程
     */

    Lock lock = new ReentrantLock();
    // 三个条件
    // 打印0的线程等待
    Condition zeroC = lock.newCondition();
    // 打印偶数的线程等待
    Condition evenC = lock.newCondition();
    // 打印奇数的线程等待
    Condition oddC = lock.newCondition();

    // 打印0的线程是否应该等待
    private volatile boolean blockZero = false;

    // 打印偶数的线程是否应该等待
    private volatile boolean blockEven = true;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {

        for (int i = 1; i <= n; i++) {
            try {
                lock.lock();
                if (blockZero) {
                    zeroC.await();
                    i--;
                    continue;
                }
                printNumber.accept(0);
                blockZero = true;
                // 根据当前i的值是奇数还是偶数来决定唤醒奇数线程的条件等待队列还是偶数条件等待队列
                if ((i & 1) == 1) {
                    oddC.signalAll();
                } else {
                    evenC.signalAll();
                }
            } finally {
                lock.unlock();
            }
        }

    }

    public void even(IntConsumer printNumber) throws InterruptedException {

        for (int i = 2; i <= n; ) {
            try {
                lock.lock();
                // 如果0线程已经执行过了 并且需要偶数线程执行
                if (blockZero && !blockEven) {
                    printNumber.accept(i);
                    i += 2;
                    blockZero = false;
                    blockEven = true;
                    zeroC.signalAll();
                    continue;
                }
                // 否则偶数线程等待
                evenC.await();
            } finally {

                lock.unlock();
            }
        }

    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; ) {
            try {
                lock.lock();
                // 如果0线程已经执行过了 并且需要奇数线程执行
                if (blockZero && blockEven) {
                    printNumber.accept(i);
                    i += 2;
                    blockZero = false;
                    blockEven = false;
                    zeroC.signalAll();
                    continue;
                }
                // 否则奇数线程等待
                oddC.await();
            } finally {
                lock.unlock();
            }
        }
    }
    
}
```