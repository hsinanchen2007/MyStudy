



1.定义number 从0开始，每次输出0 则自增1
2.wait(); notify(); 等待唤醒线程
3.if(number == n) break;



class ZeroEvenOdd {
    private int n;
    
    
    private int number = 0;

    private boolean zero = true;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }
    
    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        while (number < n) {
            synchronized (this) {
                if(!zero) {
                    wait();
                }
                printNumber.accept(0);
                number++;
                zero = false;
                notifyAll();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        while(number <= n) {
            synchronized (this) {
                if(zero){
                    wait();
                }
                if(number % 2 == 0){
                    printNumber.accept(number);
                    zero = true;
                    notifyAll();
                }
                if(number == n){
                    break;
                }
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        while(number <= n) {
            synchronized (this) {
                if(zero){
                    wait();
                }
                if(number % 2 == 1){
                    printNumber.accept(number);
                    zero = true;
                    notifyAll();
                }
                if(number == n){
                    break;
                }
            }
        }
    }
}