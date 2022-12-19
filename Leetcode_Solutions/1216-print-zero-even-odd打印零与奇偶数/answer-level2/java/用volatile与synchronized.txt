```java
class ZeroEvenOdd {
    private int n;
    private int flag = 0;
    private volatile int tempN = 1;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        while(tempN <= n){
            synchronized(this){
                while(flag != 0){
                    this.wait();
                }
                if(tempN <= n){
                    printNumber.accept(0);
                }
                //如果是奇数，则flag = 1,否则flag = 2
                flag = (tempN & 1) == 1 ? 1 : 2;
                this.notifyAll();
            } 
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        while(tempN <= n){
            synchronized(this){
                while(flag != 2){
                    this.wait();
                }
                if(tempN <= n){
                    printNumber.accept(tempN);
                }
                flag = 0;
                tempN ++;
                this.notifyAll();
            } 
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        while(tempN <= n){
            synchronized(this){
                while(flag != 1){
                    this.wait();
                }
                if(tempN <= n){
                    printNumber.accept(tempN);
                }
                flag = 0;
                tempN ++;
                this.notifyAll();
            } 
        }
    }
}
```