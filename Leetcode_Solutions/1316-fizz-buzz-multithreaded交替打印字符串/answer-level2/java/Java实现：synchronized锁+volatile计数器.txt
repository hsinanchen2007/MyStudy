
使用volatile保证计数器自增操作的可靠性，加synchronized锁避免同时操作
```java
class FizzBuzz {
    private int n;
    private volatile int i;

    public FizzBuzz(int n) {
        this.n = n;
        this.i = 1;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        
        while( true ){
            synchronized(this){
                if( i > n ){
                    this.notifyAll();
                    break;
                }
                if( i%3==0 && i%5!=0 && i<=n ){
                    printFizz.run();
                    i++;
                }
                this.notifyAll();
            }
        }
        
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        while( true ){
            synchronized(this){
                if( i > n ){
                    this.notifyAll();
                    break;
                }
                if( i%3!=0 && i%5==0 ){
                    printBuzz.run();
                    i++;
                }
                this.notifyAll();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while( true ){
            synchronized(this){
                if( i > n ){
                    this.notifyAll();
                    break;
                }
                if( i%3==0 && i%5==0 ){
                    printFizzBuzz.run();
                    i++;
                }
                this.notifyAll();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        while( true ){
            synchronized(this){
                if( i > n ){
                    this.notifyAll();
                    break;
                }
                if( i%3!=0 && i%5!=0 ){
                    printNumber.accept(i);
                    i++;
                }
                this.notifyAll();
            }
        }
        
    }
}
```
执行用时 6 ms
内存消耗 36.5 MB