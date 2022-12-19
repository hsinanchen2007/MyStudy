使用volatile变量，比semaphore信号量时间短一些
```
class ZeroEvenOdd {
    private int n;
    private volatile boolean zeroOutput=true,oddOutput=false,evenOutput=false;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i=0;i<n;i++){
            while(!zeroOutput){
                Thread.yield();
            }
            printNumber.accept(0);
            zeroOutput=false;
            if(i%2==0){
                oddOutput=true;
            }else{
                evenOutput=true;
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for(int i=2;i<=n;i+=2){
            while(!evenOutput){
                Thread.yield();
            }
            printNumber.accept(i);
            evenOutput=false;
            zeroOutput=true;
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i+=2){
            while(!oddOutput){
                Thread.yield();
            }
            printNumber.accept(i);
            oddOutput=false;
            zeroOutput=true;
        }
    }
}
```
