### 解题思路
使用ReentrantLock求解

### 代码

```java
class FizzBuzz {
    private int n;

    //标识当前打印的数
    private int i = 1;
    //全局锁
    private ReentrantLock lock = new ReentrantLock();
    //当前整数是否只被3整除的等待条件
    private Condition fizzCond = lock.newCondition();
    //当前整数是否只被5整除的等待条件
    private Condition buzzCond = lock.newCondition();
    //当前整数是否被3整除且被5整除的等待条件
    private Condition fizzbuzzCond = lock.newCondition();
    //其他等待条件
    private Condition numCond = lock.newCondition();

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        while (true) {
            lock.lock();
            try {
                //若当前整数不被3整除，则等待
                if (i % 3 != 0) {
                    fizzCond.await();
                }
                //唤醒当前线程，首先判断整数是否超过上限
                //若超出上限，则唤醒其他线程，然后结束当前线程
                if (i > n) {
                    buzzCond.signal();
                    fizzbuzzCond.signal();
                    numCond.signal();
                    break;
                }
                printFizz.run();
                //当前整数加1，判断整数是否超过上限
                //若超出上限，则唤醒其他线程，然后结束当前线程
                if (++i > n) {
                    buzzCond.signal();
                    fizzbuzzCond.signal();
                    numCond.signal();
                    break;
                }
                //唤醒number线程
                numCond.signal();
            } finally {
                lock.unlock();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        while (true) {
            lock.lock();
            try {
                //同上
                if (i % 5 != 0) {
                    buzzCond.await();
                }
                if (i > n) {
                    fizzCond.signal();
                    fizzbuzzCond.signal();
                    numCond.signal();
                    break;
                }
                printBuzz.run();
                if (++i > n) {
                    fizzCond.signal();
                    fizzbuzzCond.signal();
                    numCond.signal();
                    break;
                }
                numCond.signal();
            } finally {
                lock.unlock();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (true) {
            lock.lock();
            try {
                //同上
                if (!(i % 3 == 0 && i % 5 == 0)) {
                    fizzbuzzCond.await();
                }
                if (i > n) {
                    fizzCond.signal();
                    buzzCond.signal();
                    numCond.signal();
                    break;
                }
                printFizzBuzz.run();
                if (++i > n) {
                    fizzCond.signal();
                    buzzCond.signal();
                    numCond.signal();
                    break;
                }
                numCond.signal();

            } finally {
                lock.unlock();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        while (true) {
            lock.lock();
            try {
                //若当前整数能被3和5整除，则唤醒fizzbuzz线程，同时阻塞当前线程
                if (i % 3 == 0 && i % 5 == 0) {
                    fizzbuzzCond.signal();
                    numCond.await();
                } else if (i % 3 == 0) {
                    fizzCond.signal();
                    numCond.await();
                } else if (i % 5 == 0) {
                    buzzCond.signal();
                    numCond.await();
                } else {
                    printNumber.accept(i);
                    i++;
                }
                if (i > n) {
                    fizzCond.signal();
                    buzzCond.signal();
                    fizzbuzzCond.signal();
                    break;
                }
            } finally {
                lock.unlock();
            }
        }
    }

}
```