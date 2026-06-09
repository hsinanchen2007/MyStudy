### 解题思路
有四种打印任务：1-n的数字，3的倍数，5的倍数以及15的倍数。需要有一个线程控制信号，通知倍数线程打印字符串，我选择在数字线程来控制倍数线程的信号，3/5/15倍速打印可以在for循环中判断相应信号进行输出；
需要注意的是，3/5倍数线程在for循环开始的时候，就要把5/3的倍数数字过滤掉，否0则如果放到后面过滤，可能会由于倍数线程的顺序等原因，导致某些倍数线程卡死（比如i=15时，mod3和mod15线程已经结束，但mod5线程刚刚开始i=15的处理，导致卡死在这里），报超时异常。
性能数据：5ms  35.8MB 
### 代码

```java
class FizzBuzz {

    private int n;

    private volatile boolean mod3 = false;
    
    private volatile boolean mod5 = false;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for (int i = 3; i <= n; i += 3) {
            if (i % 5 == 0) {
                continue;
            }
            while (!mod3 || mod5) {
                Thread.yield();
            }
            synchronized(this) {
                printFizz.run();
                mod3 = false;
            }
            
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for (int i = 5; i <= n; i += 5) {
            if (i % 3 == 0) {
                continue;
            }
            while (!mod5 || mod3) {
                Thread.yield();
            }
            synchronized(this) {
                printBuzz.run();
                mod5 = false;
            }

        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 15; i <= n; i += 15) {
            while (!mod3 || !mod5) {
                Thread.yield();
            }
            synchronized(this) {
                printFizzBuzz.run();
                mod3 = false;
                mod5 = false;
            }
            
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            while (mod3 || mod5) {
                Thread.yield();
            }
            synchronized (this) {
                if (i % 3 == 0 ) {
                    mod3 = true;
                }

                if (i % 5 == 0) {
                    mod5 = true;
                }

                if (mod3 || mod5) {
                    continue;
                }
            }
            printNumber.accept(i);
        }
    }

}
```