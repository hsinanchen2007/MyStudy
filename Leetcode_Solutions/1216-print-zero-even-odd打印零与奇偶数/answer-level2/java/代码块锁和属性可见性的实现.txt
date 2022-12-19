```
package com.bobo.multiThreads;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.atomic.AtomicInteger;

public class ZeroEvenOdd {
    private int n;
    //代码块锁
    private Object object = new Object();
    //输出0的可见性锁
    private volatile boolean zeroState = false;
    //输出偶数的可见性锁
    private volatile boolean evenState = true;
    //输出奇数的可见性锁
    private volatile boolean oddState = true;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            synchronized (object) {
                while (zeroState) {
                    object.wait();
                }
                printNumber.accept(0);
                zeroState = true;
                if(i%2==0){
                    evenState = false;
                    oddState = true;
                }else{
                    oddState = false;
                    evenState = true;
                }
                object.notifyAll();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            synchronized (object) {
                while (evenState) {
                    object.wait();
                }
                if (i % 2 == 0) {
                    printNumber.accept(i);
                }
                evenState = true;
                oddState = true;
                zeroState = false;
                object.notifyAll();
            }

        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i+=2) {
            synchronized (object) {
                while (oddState) {
                    object.wait();
                }
                if (i % 2 == 1) {
                    printNumber.accept(i);
                }
                oddState = true;
                evenState = true;
                zeroState = false;
                object.notifyAll();
            }

        }
    }

    public static void main(String[] args) {
       final ZeroEvenOdd test = new ZeroEvenOdd(5);
       /* ExecutorService executors = Executors.newFixedThreadPool(3, new ThreadFactory() {
            final AtomicInteger integer = new AtomicInteger();
            @Override
            public Thread newThread(Runnable r) {
                return new Thread(r,"thread"+integer.getAndIncrement());
            }
        });*/
            Thread t1 = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        test.zero(new IntConsumer());
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            });
            Thread t2 = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        test.even(new IntConsumer());
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            });
            Thread t3 = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        test.odd(new IntConsumer());
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            });
            t1.start();
            t2.start();
            t3.start();
    }
}

class IntConsumer {

    public void accept(int i) {
        System.out.print(i);
    }
}
```
