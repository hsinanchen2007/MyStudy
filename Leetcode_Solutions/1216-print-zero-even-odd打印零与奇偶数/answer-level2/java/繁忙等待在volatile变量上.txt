class ZeroEvenOdd {
    private volatile int n;
    private volatile boolean isZero=true;
    private volatile boolean isEven=false;
    private volatile boolean isOdd=false;
    private volatile int current=0;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public final void zero(IntConsumer printNumber) throws InterruptedException {
        while(n!=0){
            while(!isZero){
                if(n==0){
                    return;
                }
                Thread.yield();
            }
            if(n==0){
                break;
            }
            printNumber.accept(0);
            isZero=false;
            if((current&1)==0){
                isOdd=true;
            }else{
                isEven=true;
            }
        }
    }

    public final void even(IntConsumer printNumber) throws InterruptedException {
        while(n!=0){
            while(!isEven){
                if(n==0){
                    return;
                }
                Thread.yield();
            }
            current=current+1;
            printNumber.accept(current);
            n--;
            isEven=false;
            isZero=true;
        }
    }

    public final void odd(IntConsumer printNumber) throws InterruptedException {
        while(n!=0){
            while(!isOdd){
                if(n==0){
                    return;
                }
                Thread.yield();
            }
            current=current+1;
            printNumber.accept(current);
            n--;
            isOdd=false;
            isZero=true;
        }
    }
}