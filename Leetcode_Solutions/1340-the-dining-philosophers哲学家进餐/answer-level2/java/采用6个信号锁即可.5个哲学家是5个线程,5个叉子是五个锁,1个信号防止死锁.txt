![image.png](https://pic.leetcode-cn.com/4abdc4e10f75df46c53f8d20093d00178e90fd119e970e86d564fbf5253d3c5b-image.png)


package com.james.leetcode;

import java.util.Random;
import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * 哲学家进餐问题.
 * Created by jianxuezhang on 2019/10/29.
 */
public class DinnerExecutor {
    static final Semaphore fork1 = new Semaphore(1);
    static final Semaphore fork2 = new Semaphore(1);
    static final Semaphore fork3 = new Semaphore(1);
    static final Semaphore fork4 = new Semaphore(1);
    static final Semaphore fork5 = new Semaphore(1);

    static final Semaphore forkControl = new Semaphore(4);


    private AtomicInteger count = new AtomicInteger(0);

    public static void main(String[] args) {
        new Thread(new Zhexuejia(1, fork5, fork1)).start();
        new Thread(new Zhexuejia(2, fork1, fork2)).start();
        new Thread(new Zhexuejia(3, fork2, fork3)).start();
        new Thread(new Zhexuejia(4, fork3, fork4)).start();
        new Thread(new Zhexuejia(5, fork4, fork5)).start();


    }

    static class Zhexuejia implements Runnable {
        int no;
        Semaphore left;
        Semaphore right;

        public Zhexuejia(int no, Semaphore left, Semaphore right) {
            this.no = no;
            this.left = left;
            this.right = right;
        }

        public void run() {
            for (int i = 1; i <= 10; i++) {
                try {

                    //拿到一个吃饭权
                    forkCountrol.acquire();
                    boolean leftFirst = new Random().nextInt(2) % 2 == 0;
                    //计算叉子坐标
                    int dot = (leftFirst ? no - 1 : no);
                    if (dot == 0)
                        dot = 5;
                    System.out.println(no + "拿到了吃饭卡,并且准备去拿" + (leftFirst ? "左边" : "右边") + "叉子=" + dot);
                    if (leftFirst) {
                        left.acquire();
                    } else {
                        right.acquire();
                    }
                    System.out.println(no + "拿到了" + (leftFirst ? "左边" : "右边") + "叉子=" + dot);
                    //刻意加大死锁概率
                    Thread.sleep(100);
                    if (leftFirst) {
                        right.acquire();
                    } else {
                        left.acquire();
                    }
                    int dot2 = (leftFirst ? no : no - 1);
                    if (dot2 == 0)
                        dot2 = 5;
                    System.out.println(no + "也拿到了另一边叉子=" + dot2);
                    System.out.println(this.no + "号哲学家在吃饭");
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } finally {
                    right.release();
                    left.release();
                    System.out.println(no + "释放了所有叉子");
                    forkControl.release();
                    System.out.println(no + "释放了吃饭卡");
                    System.out.println(this.no + "号哲学家在休息");

                }
            }
        }


    }

   
}
