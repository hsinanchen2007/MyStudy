1.由题可知每个奇偶数前面都会有0，所以先执行0再根据奇偶数特性判断下一个执行的


```
class ZeroEvenOdd {
    private int n;
    private boolean first;
    private boolean second;
    private boolean zoo = true;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        synchronized(this){
            for(int i=1;i<=n;i++){
                 while(!zoo){
                    this.wait();
                 }   
                printNumber.accept(0);
                zoo = false;
                if(i%2!=0){
                    first = true;
                }else{
                    second = true;
                }
                this.notifyAll();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        synchronized(this){
            for(int i=2;i<=n;i+=2){
                while(!second){
                    this.wait();
                }
                printNumber.accept(i);
                second = false;
                zoo = true;
                this.notifyAll();
            }
        }

    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        synchronized(this){
            for(int i=1;i<=n;i+=2){
                
                while(!first){
                    this.wait();
                }
                printNumber.accept(i);
                first = false;
                zoo = true;
                this.notifyAll();
            }
        }

    }
}
```

