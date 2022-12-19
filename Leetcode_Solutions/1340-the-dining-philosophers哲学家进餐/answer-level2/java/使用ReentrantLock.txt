1.首先我们明确产生死锁的原因是每位哲学家同时拿起左手/右手的筷子。
2.为了避免此情况，除了使用限制同时“准备吃饭”人数，可以采用让其中一位哲学家拿筷子的顺序为先右后左，其他人先左后右的顺序
这样就可以保证存在一个人可以完成吃饭动作。我们只需要为每根筷子设置锁即可，这里我们设置让0号哲学家以先右后左的顺序拿筷子
```
class DiningPhilosophers {

    public DiningPhilosophers() {
        
    }
    private ReentrantLock[] locks = {new ReentrantLock(),
		new ReentrantLock(),
		new ReentrantLock(),
		new ReentrantLock(),
		new ReentrantLock()};

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        if(philosopher==0){
            locks[philosopher].lock();
            try{
                pickRightFork.run();
                locks[(philosopher+1)%5].lock();
                try{
                    pickLeftFork.run();
                    eat.run();
                    putLeftFork.run();
                    putRightFork.run();
                }finally{
                    locks[philosopher+1].unlock();
                }
            }finally{
                locks[philosopher].unlock();
            }
        }
        else{
            locks[(philosopher+1)%5].lock();
            try{
                pickLeftFork.run();
                locks[philosopher].lock();
                try{
                    pickRightFork.run();
                    eat.run();
                    putLeftFork.run();
                    putRightFork.run();
                }finally{
                    locks[philosopher].unlock();
                }
            }finally{
                locks[(philosopher+1)%5].unlock();
            }
        }   
    }
}
```
