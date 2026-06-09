public class FizzBuzz {

    private int n;

    public FizzBuzz(int n) {
        this.n = n;
    }

    AtomicInteger m = new AtomicInteger(1);

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        int temp;
        while ((temp = m.get()) <= n) {
            if (temp % 3 == 0 && temp % 5 != 0) {
                printFizz.run();
                m.incrementAndGet();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        int temp;
        while ((temp = m.get()) <= n) {

            if (temp % 5 == 0 && temp % 3 != 0) {
                printBuzz.run();
                m.incrementAndGet();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {

        int temp;
        while ((temp = m.get()) <= n) {
            if (temp % 5 == 0 && temp % 3 == 0) {
                printFizzBuzz.run();
                m.getAndIncrement();
            }
        }

    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        int temp;
        while ((temp = m.get()) <= n) {
            if (temp % 5 != 0 && temp % 3 != 0) {
                printNumber.accept(temp);
                m.incrementAndGet();
            }
        }

    }
}
