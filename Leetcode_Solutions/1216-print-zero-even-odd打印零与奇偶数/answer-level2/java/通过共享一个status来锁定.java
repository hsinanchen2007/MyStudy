通过共享1个信号量实现
```
class ZeroEvenOdd {
    private int n;
    private volatile int status=0;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i=0;i<n;i++){
            synchronized (this){
                while(status!=0&&status!=2){
                    this.wait();
                }
                printNumber.accept(0);
                status=(status+1)%4;
                this.notifyAll();
            }    
        }  
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for(int i=2;i<=n;i+=2){
            synchronized (this){
                while(status!=3){
                    this.wait();
                }
                printNumber.accept(i);
                status=(status+1)%4;
                this.notifyAll();
            }    
        }  
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i+=2){
            synchronized (this){
                while(status!=1){
                    this.wait();
                }
                printNumber.accept(i);
                status=(status+1)%4;
                this.notifyAll();
            }    
        }  
    }
}
```

