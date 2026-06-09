```java
class ZeroEvenOdd {
    private int n;
    private Object lock;
    private int flag;
    private boolean printedZero;
    private boolean printedOdd;
    private boolean printedEven;

    public ZeroEvenOdd(int n) {
        this.n = n;
        lock = new Object();
        printedZero = false;
        printedOdd = true;
        printedEven = true;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i = 1; i<= n; i++){
            synchronized(lock){
                while(printedZero){
                    lock.wait();
                }
                printNumber.accept(0);
                printedZero = true;
                printedOdd = false;
                lock.notifyAll();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i = 1; i<= n; i++){
            synchronized(lock){
                while(printedOdd){
                    lock.wait();
                }
                if (i % 2 == 1){
                    printNumber.accept(i);
                }
                printedOdd = true;
                printedEven = false;
                lock.notifyAll();
            }
        }
    }


    public void even(IntConsumer printNumber) throws InterruptedException {
        for(int i = 1; i<= n; i++){
            synchronized(lock){
                while(printedEven){
                    lock.wait();
                }
                if(i % 2 == 0){
                    printNumber.accept(i);
                }
                printedEven = true;
                printedZero = false;
                lock.notifyAll();
            }
        }
    }
}
```
