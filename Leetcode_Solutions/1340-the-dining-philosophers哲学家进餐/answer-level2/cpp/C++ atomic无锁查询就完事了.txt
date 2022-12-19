```
class DiningPhilosophers {
private:
    enum Status {
        IDLE,BUSY
    };
    atomic<Status> forks[5];
    inline int getIndex(int i)
    {
        if (i >= 0 && i < 5)
            return i;
        else if (i < 0)
            return 4;
        else
            return 0;
    }
public:
    DiningPhilosophers() {
        for (int i = 0;i<5;++i)
            forks[i].store(Status::IDLE, memory_order_relaxed);
    }

    void wantsToEat(int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork) {
        while (1){
            if (Status::IDLE == forks[philosopher].load(memory_order_relaxed) && 
                Status::IDLE == forks[getIndex(philosopher + 1)].load(memory_order_relaxed))
            {
                forks[philosopher].store(Status::BUSY, memory_order_relaxed);
                forks[getIndex(philosopher + 1)].store(Status::BUSY, memory_order_relaxed);
                pickLeftFork();
                pickRightFork();
                eat();
                putLeftFork();
                forks[philosopher].store(Status::IDLE, memory_order_relaxed);
                putRightFork();
                forks[getIndex(philosopher + 1)].store(Status::IDLE, memory_order_relaxed);
                break;
            }
            else
                this_thread::yield();
        }
    }
};
```
