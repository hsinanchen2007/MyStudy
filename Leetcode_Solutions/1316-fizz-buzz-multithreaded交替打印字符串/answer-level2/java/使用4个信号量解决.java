使用信号量，打印3、5、15的线程先阻塞住，等打印普通数字的线程通知再打印。
打印普通数字的线程进行遍历，
如果被3整除通知3的线程、同时阻塞自己，3线程打印后，通知普通数字线程，继续遍历;
如果被5整除通知5的线程、同时阻塞自己;
如果被15整除通知15的线程、同时阻塞自己;
如果被3、5都不能整除，普通数字线程自己打印。

```
import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

class FizzBuzz {

    Semaphore fizzSem = new Semaphore(0);

    Semaphore buzzSem = new Semaphore(0);

    Semaphore fizzBuzzSem = new Semaphore(0);

    Semaphore numSem = new Semaphore(0);

    private int n;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz". 3
    public void fizz(Runnable printFizz) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 != 0) {
                fizzSem.acquire();
                printFizz.run();
                numSem.release();
            }
        }
    }

    // printBuzz.run() outputs "buzz". 5
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0 && i % 3 != 0) {
                buzzSem.acquire();
                printBuzz.run();
                numSem.release();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                fizzBuzzSem.acquire();
                printFizzBuzz.run();
                numSem.release();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 != 0) {
                fizzSem.release();
                numSem.acquire();
            } else if (i % 5 == 0 && i % 3 != 0) {
                buzzSem.release();
                numSem.acquire();
            } else if (i % 3 == 0 && i % 5 == 0) {
                fizzBuzzSem.release();
                numSem.acquire();
            } else {
                printNumber.accept(i);
            }
        }
    }

}
```
