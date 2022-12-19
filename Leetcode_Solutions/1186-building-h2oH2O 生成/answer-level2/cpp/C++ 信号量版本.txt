```

#include <semaphore.h>
// 用四个信号量，两个用来限制h和o的数量，两个用来同步h2o。
// hydrogen一次产生一个h，但需要半个o；oxygen一次产生一个o，但需要两个h
// 由于信号量没有半个的表示方法，我们对以上数字乘二
//   **即可认为hydrogen一次，产生2个h，需要1个o；oxygen一次产生2个o，但需要4个h**

class H2O
{
public:
    H2O()
    {
        sem_init(&h_limit, 0, 2);
        sem_init(&o_limit, 0, 1);
        sem_init(&h, 0, 0);
        sem_init(&o, 0, 0);
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        sem_wait(&h_limit);   
        sem_post(&h);
        sem_post(&h);
        sem_wait(&o);
        releaseHydrogen();
        sem_post(&h_limit);
    }

    void oxygen(function<void()> releaseOxygen)
    {
        sem_wait(&o_limit);
        sem_post(&o);
        sem_post(&o);
        sem_wait(&h);
        sem_wait(&h);
        sem_wait(&h);
        sem_wait(&h);
        releaseOxygen();
        sem_post(&o_limit);
    }

private:
    sem_t h_limit, o_limit, h, o;
};
```



