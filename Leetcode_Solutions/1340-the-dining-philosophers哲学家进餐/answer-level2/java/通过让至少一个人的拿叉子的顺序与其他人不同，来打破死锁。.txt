1.首先要对问题进行抽象化并构建规则：


第一步：某个哲学家拿起了一个叉子，那么在他放下这个叉子之前另外一个相邻的哲学家是不能拿这个叉子的------>说明每个叉子代表一个锁，在某个哲学家
调用这个叉子之前上锁，其他线程进来了就得等待这个锁被释放才能拿到叉子的使用权。

第二步：很明显，会出现两种导致程序陷入***死锁***的情况： 
所有的哲学家都先拿左手/右手的叉子，结果在某次执行的时候，出现： 哲学家m0开启左手/右手叉子锁->哲学家m1开启左手/右手叉子锁->哲学家m2开启左手/右手叉子锁->
哲学家m3开启左手/右手叉子锁->哲学家m4开启左手/右手叉子锁. 结果导致程序进入死锁。

为了避免这种情况，就需要改进所有哲学家都先拿某一手边叉子的做法，让至少一个哲学家与其他人拿叉子的左右先后顺序不同，就可以打破程序进入死锁的流程，从而
让程序顺利地执行下去。
```
class DiningPhilosophers {
    private  final Lock [] lockFork  = {new ReentrantLock(),
                                    new ReentrantLock(),
                                    new ReentrantLock(),
                                    new ReentrantLock(),
                                    new ReentrantLock(),
                                    };
    
    public DiningPhilosophers() {
        
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        int leftForkNumber = (philosopher+4) % 5;
        int rightForkNumber = philosopher;
        if (philosopher == 4){
         lockFork [leftForkNumber].lock();
         lockFork [rightForkNumber].lock();
        }
         else 
         {
            lockFork [rightForkNumber].lock();
            lockFork [leftForkNumber].lock();
         }
            pickLeftFork.run();
            pickRightFork.run();
            eat.run();
            putLeftFork.run();
            putRightFork.run();       
   
            lockFork [rightForkNumber].unlock();
            lockFork [leftForkNumber].unlock();

    }
}
```
