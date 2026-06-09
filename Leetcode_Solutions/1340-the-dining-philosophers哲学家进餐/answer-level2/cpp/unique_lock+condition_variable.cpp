
记得操作系统里说过哲学家问题有两种防止死锁的方式：1.规划拿筷子的顺序 2.竞争筷子时，要么拿一双，要么一根也不拿。
参照了[@lxdlam](/u/lxdlam/)这位同学的代码，他的代码解释是第一种防止死锁的方式，即规划了拿筷子的顺序，先拿小编号，再拿大编号，防止死锁，但是我觉得他代码里那种写法是要么拿一双，要么都不拿，所以我改了下代码，发现果真如此。

```
class DiningPhilosophers {
private:
    std::mutex mu;
    std::condition_variable cv;
    bool isusing[5];
public:
    DiningPhilosophers() {
        for(int i=0;i<5;i++)
            isusing[i]=false;
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int left=philosopher;
        int right=(philosopher+1)%5;
        
        unique_lock<mutex> lk(mu);
        cv.wait(lk,[&left,&right,this](){return !isusing[left]&&!isusing[right];});//要么不拿，要么拿一双
        isusing[left]=true;
        isusing[right]=true;
        lk.unlock();
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        lk.lock();
        isusing[left]=false;
        isusing[right]=false;
        lk.unlock();
        cv.notify_all();
    }
};
```
