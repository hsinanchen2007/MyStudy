### 方法一：锁
#### 分析：
- 设置一个每个线程共有的变量`i`，用来代表当前的数字
- 将每一个判断并打印的操作，放在一个同步代码块内部，以保证操作的原子性，使得所有操作串行发生
- 每一个线程内部，当`i`小于等于`n`时，不断的争用同一把锁。
- 当线程得到锁后，判断当前的数字`i`是否满足自身的打印条件,若是则打印,并将`i+1`,否则放弃这把锁。

#### 实现：
```java []
class FizzBuzz {
    private int n;
    private int i;
    private Object lock = new Object();

    public FizzBuzz(int n) {
        this.n = n;
        this.i = 1;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        while (i <= n) {
            synchronized(lock) {
                while (i <= n && i % 3 == 0 && i % 5 != 0) {
                    printFizz.run();
                    i++; 
                }
            }
        }
        
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        while (i <= n) {
            synchronized(lock) {
                while (i <= n && i % 3 != 0 && i % 5 == 0) {
                    printBuzz.run();
                    i++;
                } 
            }
        }
        
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (i <= n) {
            synchronized(lock) {
                while (i <= n && i % 3 == 0 && i % 5 == 0) {
                    printFizzBuzz.run();
                    i++;
                }
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        while (i <= n) {
             synchronized(lock) {
                while (i <= n && i % 3 != 0 && i % 5 != 0) {
                    printNumber.accept(i);
                    i++; 
                }
            }
        }
       
    }
}
```

