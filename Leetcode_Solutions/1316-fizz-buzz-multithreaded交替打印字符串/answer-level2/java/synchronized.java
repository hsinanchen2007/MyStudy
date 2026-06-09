```
class FizzBuzz {

        int item = 1;

        private int n;

        public FizzBuzz(int n) {
            this.n = n;
        }

        // printFizz.run() outputs "fizz".
        public void fizz(Runnable printFizz) throws InterruptedException {
            //如果这个数字可以被 3 整除，输出 "fizz"
            while (true) {
                synchronized (this) {
                    if (item > n) {
                        break;
                    }
                    if (item % 3 == 0 && item % 5 != 0) {
                        printFizz.run();
                        item++;
                    }
                }
            }

        }

        // printBuzz.run() outputs "buzz".
        public void buzz(Runnable printBuzz) throws InterruptedException {
            //如果这个数字可以被 5 整除，输出 "buzz"
            while (true) {
                synchronized (this) {
                    if (item > n) {
                        break;
                    }
                    if (item % 3 != 0 && item % 5 == 0) {
                        printBuzz.run();
                        item++;
                    }
                }
            }
        }

        // printFizzBuzz.run() outputs "fizzbuzz".
        public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
            //如果这个数字可以同时被 3 和 5 整除，输出 "fizzbuzz"
            while (true) {
                synchronized (this) {
                    if (item > n) {
                        break;
                    }
                    if (item % 3 == 0 && item % 5 == 0) {
                        printFizzBuzz.run();
                        item++;
                    }
                }

            }
        }

        // printNumber.accept(x) outputs "x", where x is an integer.
        public void number(IntConsumer printNumber) throws InterruptedException {
            while (true) {
                synchronized (this) {
                    if (item > n) {
                        break;
                    }
                    if (item % 3 != 0 && item % 5 != 0) {
                        printNumber.accept(item);
                        item++;
                    }
                }

            }
        }
    }
```
