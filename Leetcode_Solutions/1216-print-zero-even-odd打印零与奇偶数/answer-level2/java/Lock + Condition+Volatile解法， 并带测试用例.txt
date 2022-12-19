```java
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.function.IntConsumer;

/**
 * 解法:
 *  1. i自增的时候, 需要注意增加幅度, 若是只是自增1; 会导致线程被wait; 没有其它的线程去唤醒;
 *  2. unlock一定放在finally中, 防止出现异常, 无法释放锁.
 *  3. 主要根据zero的循环index来设置flag, 到底需要打印even还是odd.
 *  4. 不管even还是odd, 执行完成时, 都应该设置flag = 0; 因为不管是打印even还是odd, 接着都要打印zero; 然后再选择打印even还是odd. 
 */
class ZeroEvenOdd {    
    private int n;

    private final Lock lock = new ReentrantLock();

    private final Condition condition = lock.newCondition();

    private volatile int flag = 0;

    public ZeroEvenOdd(int n) {        
        this.n = n;
    }
    
    public void zero(IntConsumer printNumber) throws InterruptedException {
        try {
            lock.lock();
            for (int i = 1; i <= n; i++) {                
                while (flag != 0) {
                    condition.await();
                }
                
                if (i % 2 == 0) {
                    flag = 1;
                } else {                    
                    flag = 2;
                }
                
                printNumber.accept(0);
                condition.signalAll();
            }        
        } finally {
            lock.unlock();
        }    
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        try {
            lock.lock();
            for (int i = 2; i <= n; i += 2) {               
                while (flag != 1) {
                    condition.await();
                }
                
                flag = 0;
                printNumber.accept(i);
                condition.signalAll();
            }        
        } finally {
            lock.unlock();
        }    
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        try {
            lock.lock();
            for (int i = 1; i <= n; i += 2) {                
                while (flag != 2) {
                    condition.await();
                }
                
                flag = 0;
                printNumber.accept(i);
                condition.signalAll();
            }        
        } finally {
            lock.unlock();
        }    
    }

    public static void main(String[] args) {
        ZeroEvenOdd zeroEvenOdd = new ZeroEvenOdd(10);

        new Thread(() -> {            
            try {
                zeroEvenOdd.zero(System.out::print);
            } catch (InterruptedException e) {                
                e.printStackTrace();
            }        
        }).start();

        new Thread(() -> {            
            try {
                zeroEvenOdd.even(System.out::print);
            } catch (InterruptedException e) {                
                e.printStackTrace();
            }        
        }).start();

        new Thread(() -> {            
            try {
                zeroEvenOdd.odd(System.out::print);
            } catch (InterruptedException e) {                
                e.printStackTrace();
            }        
        }).start();
    }
}
```
