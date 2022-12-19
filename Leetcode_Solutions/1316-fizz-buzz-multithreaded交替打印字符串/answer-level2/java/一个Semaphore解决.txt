    class FizzBuzz {
        private int n;
        private Semaphore semaphore = new Semaphore(1);
        private int i;
        public FizzBuzz(int n) {
            this.n = n;
            this.i = 1;
        }

        // printFizz.run() outputs "fizz".
        public void fizz(Runnable printFizz) throws InterruptedException {
            while(i <= n){
                if(i%3 == 0 && i%5 != 0){
                    semaphore.acquire();
                    printFizz.run();
                    ++i;
                    semaphore.release();
                }
            }
        }

        // printBuzz.run() outputs "buzz".
        public void buzz(Runnable printBuzz) throws InterruptedException {
            while(i <= n){
                if(i%5 == 0 && i%3 != 0){
                    semaphore.acquire();
                    printBuzz.run();
                    ++i;
                    semaphore.release();
                }
            }
        }

        // printFizzBuzz.run() outputs "fizzbuzz".
        public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
            while(i <= n){
                if(i%3 == 0 && i%5 == 0){
                    semaphore.acquire();
                    printFizzBuzz.run();
                    ++i;
                    semaphore.release();
                }
            }
        }

        // printNumber.accept(x) outputs "x", where x is an integer.
        public void number(IntConsumer printNumber) throws InterruptedException {
            while(i <= n){
                if(i%3 != 0 && i%5 != 0){
                    semaphore.acquire();
                    printNumber.accept(i);
                    ++i;
                    semaphore.release();
                }
            }
        }
    }