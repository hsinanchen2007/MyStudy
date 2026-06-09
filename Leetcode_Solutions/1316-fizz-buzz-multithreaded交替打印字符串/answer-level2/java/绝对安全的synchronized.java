```
class FizzBuzz {
    private int n;
    private volatile int current=1;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public final void fizz(Runnable printFizz) throws InterruptedException {
        while(current<=n){
            synchronized(this){
                if(current>n){return;}
                if((current%3==0)&&(current%5!=0)){
                    printFizz.run();
                    current++;
                    this.notifyAll();
                }else{
                    this.wait();
                }
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public final void buzz(Runnable printBuzz) throws InterruptedException {
        while(current<=n){
            synchronized(this){
                if(current>n){return;}
                if((current%3!=0)&&(current%5==0)){
                    printBuzz.run();
                    current++;
                    this.notifyAll();
                }else{
                    this.wait();
                }
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public final void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while(current<=n){
            synchronized(this){
                if(current>n){return;}
                if((current%3==0)&&(current%5==0)){
                    printFizzBuzz.run();
                    current++;
                    this.notifyAll();
                }else{
                    this.wait();
                }
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public final void number(IntConsumer printNumber) throws InterruptedException {
        while(current<=n){
            synchronized(this){
                if(current>n){return;}
                if((current%3!=0)&&(current%5!=0)){
                    printNumber.accept(current);
                    current++;
                    this.notifyAll();
                }else{
                    this.wait();
                }
            }
        }
    }
}
```
