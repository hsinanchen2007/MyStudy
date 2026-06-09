```
class FizzBuzz {
    private int n;
    private volatile int current=1;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        while(current<=n){
            if((current%3==0)&&(current%5!=0)){
                printFizz.run();
                current++;
            }else{
                Thread.yield();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        while(current<=n){
            if((current%3!=0)&&(current%5==0)){
                printBuzz.run();
                current++;
            }else{
                Thread.yield();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while(current<=n){
            if((current%3==0)&&(current%5==0)){
                printFizzBuzz.run();
                current++;
            }else{
                Thread.yield();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        while(current<=n){
            if((current%3!=0)&&(current%5!=0)){
                printNumber.accept(current);
                current++;
            }else{
                Thread.yield();
            }
        }
    }
}
```
