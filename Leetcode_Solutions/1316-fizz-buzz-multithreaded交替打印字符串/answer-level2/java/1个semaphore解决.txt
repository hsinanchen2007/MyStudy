```java []
class FizzBuzz {
    private int n;
    Semaphore semaphore = new Semaphore(1);
    int i = 1;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        while (i <= n) {
            semaphore.acquire(1);
            if (i <= n) {
                if ((i % 3 == 0) && (i % 5 != 0)) {
                    printFizz.run();
                    i++;
                }
            }
            semaphore.release(1);
        }

    }


    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        while (i <= n) {
            semaphore.acquire(1);
            if (i <= n) {
                if ((i % 5 == 0) && (i % 3 != 0)) {
                    printBuzz.run();
                    i++;
                }
            }
            semaphore.release(1);
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (i <= n) {
            semaphore.acquire(1);
            if (i <= n) {
                if ((i % 5 == 0) && (i % 3 == 0)) {
                    printFizzBuzz.run();
                    i++;
                }
            }
            semaphore.release(1);
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        while (i <= n) {
            semaphore.acquire(1);
            if (i <= n) {
                if ((i % 5 != 0) && (i % 3 != 0)) {
                    printNumber.accept(i);
                    i++;
                }
            }
            semaphore.release(1);
        }
    }
}
```
算双检锁嘛...