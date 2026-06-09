import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.function.IntConsumer;

class FizzBuzz {
    private int n;
    private int i = 1;
    private Lock lock = new ReentrantLock();

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        while (i <= n) {
            lock.lock();
            if (i <= n && i % 3 == 0 && i % 15 != 0) {
                printFizz.run();
                i++;
            }
            lock.unlock();
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        while (i <= n) {
            lock.lock();
            if (i <= n && i % 5 == 0 && i % 15 != 0) {
                printBuzz.run();
                i++;
            }
            lock.unlock();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (i <= n) {
            lock.lock();
            if (i <= n && i % 3 == 0 && i % 5 == 0) {
                printFizzBuzz.run();
                i++;
            }
            lock.unlock();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        while (i <= n) {
            lock.lock();
            if (i <= n && i % 3 != 0 && i % 5 != 0) {
                printNumber.accept(i);
                i++;
            }
            lock.unlock();
        }
    }
}
