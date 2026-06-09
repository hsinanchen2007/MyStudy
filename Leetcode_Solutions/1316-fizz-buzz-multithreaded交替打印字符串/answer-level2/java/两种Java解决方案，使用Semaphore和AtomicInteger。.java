解题思路简单说明：
- 两种解决方案中，分别使用到了Semaphore及AtomicInteger来完成线程间互斥。
- 使用AtomicInteger时，使用了while及LockSupport来完成线程等待。

1. Semaphore解决方案
```
class FizzBuzz {
    // Initialize the permit, limit to one.
    private Semaphore sema = new Semaphore(1);
    
    // The current number.
    private int curNum = 1;
    
    private int n;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for(;;) {
            // Acquire the permit, try to run the logic exclusively.
            this.sema.acquire(1);
            
            try {
                if (this.curNum > n) {
                    return;    
                }
                
                if ((this.curNum % 3 == 0) && (this.curNum % 5 != 0)) {
                    printFizz.run();    
                    this.curNum++;
                }
            } finally {
                // Release the permit anyway.
                this.sema.release(1);
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for(;;) {            
            this.sema.acquire(1);
                
            try {
                if (this.curNum > n) {
                    return;
                }
                
                if ((this.curNum % 3 != 0) && (this.curNum % 5 == 0)) {
                    printBuzz.run();
                    this.curNum++;
                }    
            } finally {
                this.sema.release(1);
            }   
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for(;;) {
            this.sema.acquire(1);
                
            try {
                if (this.curNum > n) {
                    return;
                }
                
                if ((this.curNum % 3 == 0) && (this.curNum % 5 == 0)) {
                    printFizzBuzz.run();    
                    this.curNum++;
                }
            } finally {
                this.sema.release(1);
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for(;;) {
            this.sema.acquire(1);
        
            try {
                if (this.curNum > n) {
                    return;
                }
                
                if ((this.curNum % 3 != 0) && (this.curNum % 5 != 0)) {
                    printNumber.accept(this.curNum);  
                    this.curNum++;
                }
            } finally {
                this.sema.release(1);
            }
        }
    }
}
```

2. AtomicInteger解决方案
```
class FizzBuzz {
    // Initialize the flag.
    private AtomicInteger state = new AtomicInteger(1);
    
    // The current number.
    private int curNum = 1;
    
    private int n;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for(;;) {
            // Update the current state using CAS in orde to run the logic exclusively.
            while (!this.state.compareAndSet(1, 0)) {
                // Alleviate the busy spin.
                LockSupport.parkNanos(1L);
            }
            
            if (this.curNum > n) {
                // Reset the state before return, then other waiting threads can terminate.
                this.state.set(1);
                return;
            }
                
            if ((this.curNum % 3 == 0) && (this.curNum % 5 != 0)) {
                printFizz.run();    
                this.curNum++;
            }
            
            this.state.set(1);
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for(;;) {            
            while (!this.state.compareAndSet(1, 0)) {
                LockSupport.parkNanos(1L);
            }
                
            if (this.curNum > n) {    
                this.state.set(1);
                return;
            }
                
            if ((this.curNum % 3 != 0) && (this.curNum % 5 == 0)) {
                printBuzz.run();
                this.curNum++;    
            }
            
            this.state.set(1);   
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for(;;) {
            while (!this.state.compareAndSet(1, 0)) {
                LockSupport.parkNanos(1L);
            }
            
            if (this.curNum > n) {
                this.state.set(1);
                return;
            }
                
            if ((this.curNum % 3 == 0) && (this.curNum % 5 == 0)) {    
                printFizzBuzz.run();    
                this.curNum++;    
            }
            
            this.state.set(1);
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for(;;) {
            while (!this.state.compareAndSet(1, 0)) {
                LockSupport.parkNanos(1L);
            }
            
            if (this.curNum > n) {    
                this.state.set(1);
                return;
            }
                    
            if ((this.curNum % 3 != 0) && (this.curNum % 5 != 0)) {    
                printNumber.accept(this.curNum);  
                this.curNum++;
            }
            
            this.state.set(1);
        }
    }
}
```
