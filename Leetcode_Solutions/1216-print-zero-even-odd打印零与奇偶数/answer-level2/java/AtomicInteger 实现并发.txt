```
class ZeroEvenOdd {
    private int n;
    //ati用来控制下标
    private AtomicInteger ati=new AtomicInteger(0);
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        //for循环控制打印0的个数
        for(int i=0;i<2*n;i=i+2){
            while(ati.get()%2!=0) {Thread.yield();}
            printNumber.accept(0);
            ati.getAndIncrement();
        }

    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        //for循环控制打印的数值 ！！！
        for(int i=2;i<=n;i+=2){
            while(ati.get()%4!=3) {Thread.yield();}
            printNumber.accept(i);
            ati.getAndIncrement();
        }

       
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        //for循环控制打印的数值 ！！！
        for(int i=1;i<=n;i+=2){
            while(ati.get()%4!=1) {Thread.yield();}
            printNumber.accept(i);
            ati.getAndIncrement();
        }
    }
}
```
