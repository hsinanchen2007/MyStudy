```
class FizzBuzz {
    // 1. synchronized
    private int n;
    private int start;
    private Object lock = new Object();

    public FizzBuzz(int n) {
        this.n = n;
        this.start = 1;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        synchronized (lock) {
            while (start <= n) {
                if (start % 3 == 0 && start % 5 != 0) {
                    printFizz.run();
                    start++;
                    lock.notifyAll();
                } else {
                    lock.wait();
                }
            }
            lock.notifyAll();
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        synchronized (lock) {
            while (start <= n) {
                if (start % 3 != 0 && start % 5 == 0) {
                    printBuzz.run();
                    start++;
                    lock.notifyAll();
                } else {
                    lock.wait();
                }
            }
            lock.notifyAll();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        synchronized (lock) {
            while (start <= n) {
                if (start % 3 == 0 && start % 5 == 0) {
                    printFizzBuzz.run();
                    start++;
                    lock.notifyAll();
                } else {
                    lock.wait();
                }
            }
            lock.notifyAll();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        synchronized (lock) {
            while (start <= n) {
                if (start % 3 != 0 && start % 5 != 0) {
                    printNumber.accept(start++);
                    lock.notifyAll();
                } else {
                    lock.wait();
                }
            }
            lock.notifyAll();
        }
    }
}
```
