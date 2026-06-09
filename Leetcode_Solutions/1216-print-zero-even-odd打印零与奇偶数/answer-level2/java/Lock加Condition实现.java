import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class ZeroEvenOdd {
    private int n;
    
    private int flag = 0;
    Lock lock = new ReentrantLock();
    Condition conditionZero = lock.newCondition();
    Condition conditionOdd = lock.newCondition();
    Condition conditionEven = lock.newCondition();
    int i = 0;


    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int j = 0;j < n ; j++){
            lock.lock();
            try{
                while(flag != 0){
                    conditionZero.await();
                }

                printNumber.accept(0);
                i++;
                flag = i%2;
                if(flag == 1){
                    conditionOdd.signal();
                }else{
                    flag = 2;
                    conditionEven.signal();
                }
            }finally {
                lock.unlock();
            }
        }

    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for(int  k = 0 ; k < (n / 2);k++){
            lock.lock();
            try{
                while(flag != 2){
                    conditionEven.await();
                }

                printNumber.accept(i);
                flag = 0;
                conditionZero.signal();

            }finally {

                lock.unlock();
            }

        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for(int  m = 0 ; m < Math.round( (float) n / 2) ; m++){
            lock.lock();
            try{
                while(flag != 1){
                    conditionOdd.await();
                }

                printNumber.accept(i);
                flag = 0;
                conditionZero.signal();
            }finally {
                lock.unlock();
            }

        }
    }
}