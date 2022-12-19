### 解题思路
Semaphore  普通使用

### 代码

```java
public class FizzBuzz {

    private Semaphore fizz = new Semaphore(0);

    private Semaphore buzz = new Semaphore(0);

    private Semaphore fizzbuzz = new Semaphore(0);

    private Semaphore number = new Semaphore(1);

    private volatile int n;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for(int i = 3;i <= n;i+=3){
            if(i % 5 == 0)
                continue;
            fizz.acquire();
            printFizz.run();
            number.release();
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for(int i = 5;i <= n;i+=5){
            if(i % 3 == 0)
                continue;
            buzz.acquire();
            printBuzz.run();
            number.release();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for(int i = 15;i <= n;i+=15){
            fizzbuzz.acquire();
            printFizzBuzz.run();
            number.release();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            number.acquire();
            if (i % 3 == 0 && i % 5 == 0) {
                fizzbuzz.release();
            }else if(i % 3 == 0){
                fizz.release();
            }else if(i % 5 == 0){
                buzz.release();
            }else{
                printNumber.accept(i);
                number.release();
            }

        }
    }
}

```ReentrantLock 使用
```
```java
public class FizzBuzz {

    private ReentrantLock lock = new ReentrantLock(false);

    private Condition fCondition = lock.newCondition();

    private Condition bCondition = lock.newCondition();

    private Condition fbCondition = lock.newCondition();

    private Condition nCondition = lock.newCondition();

    private volatile int n;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for(int i = 3;i <= n;i+=3){
            if(i % 5 == 0)
                continue;
            lock.lock();
            try {
                fCondition.await();
                printFizz.run();
                nCondition.signal();
            }finally {
                lock.unlock();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {

        for(int i = 5;i <= n;i+=5){
            if(i % 3 == 0)
                continue;
            lock.lock();
            try {
                bCondition.await();
                printBuzz.run();
                nCondition.signal();
            }finally {
                lock.unlock();
            }

        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
            for(int i = 15;i <= n;i+=15){
                lock.lock();
                try {
                    fbCondition.await();
                    printFizzBuzz.run();
                    nCondition.signal();
                }finally {
                    lock.unlock();
                }

            }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            lock.lock();
            try {
                if (i % 3 == 0 && i % 5 == 0) {
                    fbCondition.signal();
                    nCondition.await();
                }else if(i % 3 == 0){
                    fCondition.signal();
                    nCondition.await();
                }else if(i % 5 == 0){
                    bCondition.signal();
                    nCondition.await();
                }else{
                    printNumber.accept(i);
                }
            }finally {
                lock.unlock();
            }
        }
    }
}

```
```
