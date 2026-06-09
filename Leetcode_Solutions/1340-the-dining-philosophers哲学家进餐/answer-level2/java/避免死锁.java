### 解题思路
产生死锁的四个条件：
1.互斥
2.持有部分锁并等待占有其他锁
3.已持有的锁不可抢夺
4.循环等待

可以破坏除了第一个条件以外的三个条件来打破死锁，我是通过给拿锁和持有锁一个随时超时时间来避免死锁，代码如下：

### 代码

```java
class DiningPhilosophers {

   Object[][] cz = new Object[5][3];
    private int size = 10;


    public DiningPhilosophers() {
        //创建五个叉子
        Lock l1 = new ReentrantLock( true );
        Lock l2 = new ReentrantLock( true );
        Lock l3 = new ReentrantLock( true );
        Lock l4 = new ReentrantLock( true );
        Lock l5 = new ReentrantLock( true );
        //给每个哲学家分配好左边以及右边的叉子
        cz[0][2] = l1;
        cz[0][1] = l5;
        cz[1][1] = l1;
        cz[1][2] = l2;
        cz[2][1] = l2;
        cz[2][2] = l3;
        cz[3][1] = l3;
        cz[3][2] = l4;
        cz[4][1] = l4;
        cz[4][2] = l5;


    }

    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        //准备好两边的叉子 准备占有
        Lock leftLock = (Lock) cz[philosopher][1];
        Lock rightLock = (Lock) cz[philosopher][2];

        int random = new Random().nextInt( 100 ) + 1;
        long start = System.currentTimeMillis();
        f1:for(int i=0;;i++){
            //尝试占有左边的叉子
            if(leftLock.tryLock( random, TimeUnit.MILLISECONDS )){
                f2:for(int k=0;;k++){
                    //尝试占有右边的叉子
                    if(!rightLock.tryLock( random,TimeUnit.MILLISECONDS )){
                        if(System.currentTimeMillis()-start>=(size*random)){
                            //如果占有右边的叉子超时了，那么释放左边的叉子，
                            //重新尝试，避免死锁
                            leftLock.unlock();
                            break f2;
                        }
                    }else{
                        //如果都拿到了，那么跳出循环
                        break f1;
                    }
                }
            }
        }
                //开始吃
                pickLeftFork.run();
                pickRightFork.run();
                eat.run();
                putLeftFork.run();
                putRightFork.run();
                rightLock.unlock();
                leftLock.unlock();




    }
}
```