```
package com.medium;

import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * @author qinzhu
 * @since 2019/10/31
 */
public class DiningPhilosophers  {

    public static void main(String[] args) {
        DiningPhilosophers  o = new DiningPhilosophers ();
        int eatNumber = 2;
        for (int i = 0; i < peopleNumber; i++) {
            final int tmp = i;
            new Thread(() -> {
                for (int j = 0; j < eatNumber; j++) {
                    try {
                        o.wantsToEat(tmp, () -> {
                            System.out.println(tmp + ":拿起左边");
                        },() -> {
                            System.out.println(tmp + ":拿起右边");
                        },() -> {
                            System.out.println(tmp + ":吃");
                        },() -> {
                            System.out.println(tmp + ":放下左边");
                        },() -> {
                            System.out.println(tmp + ":放下右边");
                        });
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
    }

    private static final int peopleNumber = 5;

    // 有5个餐具，使用4个信号量，限制同一时刻只能有4个人去拿餐具
    // 所以肯定不会出现，因为至少有一个人能同时获得左右的餐具
    private Semaphore peopleSemaphore = new Semaphore(peopleNumber - 1);

    // 餐具的锁，防止同一个时刻一把餐具被两个人拿到
    private Lock[] forkLocks;

    public DiningPhilosophers () {
        initLock(peopleNumber);
    }

    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        int letFork = philosopher;
        int rightFork = (philosopher + 1) % peopleNumber;
        try {
            peopleSemaphore.acquire();
            forkLocks[letFork].lock();
            pickLeftFork.run();
            forkLocks[rightFork].lock();
            pickRightFork.run();
            eat.run();
            putLeftFork.run();
            putRightFork.run();
        } finally {
            forkLocks[rightFork].unlock();
            forkLocks[letFork].unlock();
            peopleSemaphore.release();
        }

    }

    private void initLock(int count) {
        this.forkLocks = new ReentrantLock[count];
        for (int i = 0; i < count; i++) {
            forkLocks[i] = new ReentrantLock();
        }
    }
}

```
