class FizzBuzz {
    private volatile int n;
    private volatile int  f = 1;
    private volatile int state = 0;
    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
       while(f<=n){                
            if(f%3==0&&f%5!=0&&state==1){
                printFizz.run();
                state=0;
            }
       } 
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
       while(f<=n){
            if(f%5==0&&f%3!=0&&state==2){
                printBuzz.run();
                state=0;
            }
       }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
         while(f<=n){
            if(f%5==0&&f%3==0&&state==3){
                printFizzBuzz.run();
                state=0;
            }
       }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
      while(f<=n){
          if(state==0){
            if(f%3!=0&&f%5!=0){
                printNumber.accept(f);            
            }
            f = f+1;           
            if(f%3!=0&&f%5!=0){        
                state=0;
            }else if(f%3==0&&f%5!=0){
                state=1;
                Thread.sleep(0);
            }else if(f%3!=0&&f%5==0){
                state=2;
            }else if(f%3==0&&f%5==0){
                state=3;
            }
          }
           
        }
    }
