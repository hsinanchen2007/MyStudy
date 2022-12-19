打印的顺序是固定的first，second，third。需要有一个通知机制来阻止和唤醒那一条线程阻塞，那一条执行。
先利用lock对方法进行加锁，再利用Condition进行方法的执行顺序

```
package bsoft.com.threadCode;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class PrintInOrder {

    private Lock  lock=new ReentrantLock();
    private Condition c1= lock.newCondition();
    private Condition c2= lock.newCondition();
    private Condition c3= lock.newCondition();
    private int number=1;

    public void first(Runnable printFirst)throws InterruptedException{
        lock.lock();
        try {
            while(number!=1){
                c1.await();
            }
            printFirst.run();
            number=2;
            c2.signal();
        }catch (Exception e){
            throw e;
        }finally {
            lock.unlock();
        }

    }
    public void second(Runnable printSecond)throws InterruptedException{
        lock.lock();
        try {
            while(number!=2){
                c2.await();
            }
            printSecond.run();
            number=3;
            c3.signal();
        }catch (Exception e){
            throw e;
        }finally {
            lock.unlock();
        }

    }
    public void third(Runnable printThird)throws InterruptedException{
        lock.lock();
        try {
            while (number!=3){
                c3.await();
            }
            printThird.run();
            number=1;
            c1.signal();
        }catch (Exception e){
            throw e;
        }finally {
            lock.unlock();
        }

    }

    public static void main(String[] args)throws Exception {
        PrintInOrder printInOrder=new PrintInOrder();

        printInOrder.first(new Runnable() {
            @Override
            public void run() {
                System.out.println("print first");
            }
        });

        printInOrder.second(new Runnable() {
            @Override
            public void run() {
                System.out.println("print second");
            }
        });

        printInOrder.third(new Runnable() {
            @Override
            public void run() {
                System.out.println("print third");
            }
        });
    }
}

```
