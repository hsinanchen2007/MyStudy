class FizzBuzz {
    private int n;

    public FizzBuzz(int n) {
        this.n = n;
    }
    private volatile int num = 1;
    private Lock lock = new ReentrantLock();
    Condition condition = lock.newCondition();
    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        lock.lock();
        try{
            while(num <=n){
                while(num<=n && num%3!=0 || num%5==0){
                    condition.await();
                }
                if(num>n){
                    break;
                }
                printFizz.run();
                num++;
                condition.signalAll();
            }

        }finally {
            lock.unlock();
        }

    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        lock.lock();
        try{
            while(num<=n){
                while(num<=n && num%5!=0 || num%3==0){
                    condition.await();
                }
                if(num>n){
                    break;
                }
                printBuzz.run();
                num++;
                condition.signalAll();
            }
        }finally {
            lock.unlock();
        }

    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        lock.lock();
        try{
            while(num<=n){
                while(num<=n && (num%3!=0 || num%5!=0) ){
                    condition.await();
                }
                if(num>n){
                    break;
                }
                printFizzBuzz.run();
                num++;
                condition.signalAll();
            }

        }finally {
            lock.unlock();
        }

    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        lock.lock();
        try{
            while(num<=n){
                while(num<=n && (num%3==0 || num%5==0)){
                    condition.await();
                }
                if(num>n){
                    break;
                }
                printNumber.accept(num);
                num++;
                condition.signalAll();
            }
        }finally {
            lock.unlock();
        }

    }
}