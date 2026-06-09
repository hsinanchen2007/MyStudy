### 解题思路
依次释放而已

### 代码

```java
class FizzBuzz {
    private int n;

    private AtomicInteger ai ;

    private Semaphore print3Lock;
    private Semaphore print5Lock;
    private Semaphore print15Lock;
    private Semaphore printZLock;

    public FizzBuzz(int n) {
        this.n = n;
        ai = new AtomicInteger(1);
        print3Lock = new Semaphore(0);
        print5Lock = new Semaphore(0);
        print15Lock = new Semaphore(0);
        printZLock = new Semaphore(1);
    }

    private boolean next(){
        ai.incrementAndGet();
        if(ai.get() > this.n){
            print15Lock.release(1);
            print3Lock.release(1);
            print5Lock.release(1);
            printZLock.release(1);
            return false;
        }
        if (ai.get() % 15 == 0) {
            print15Lock.release(1);
        } else if (ai.get() % 3 == 0) {
            print3Lock.release(1);
        } else if (ai.get() % 5 == 0) {
            print5Lock.release(1);
        } else{
            printZLock.release(1);
        }
        return true;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        while(true){
            print3Lock.acquire();
            if(this.ai.get() > this.n){
                return;
            }
            printFizz.run();
            next();
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        while(true) {
            print5Lock.acquire();
            if(this.ai.get() > this.n){
                return;
            }
            printBuzz.run();
            next();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while(true) {
            print15Lock.acquire();
            if(this.ai.get() > this.n){
                return;
            }
            printFizzBuzz.run();
            next();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        while(true) {
            printZLock.acquire();
            if(this.ai.get() > this.n){
                return;
            }
            printNumber.accept(ai.get());
            next();
        }
    }
}
```