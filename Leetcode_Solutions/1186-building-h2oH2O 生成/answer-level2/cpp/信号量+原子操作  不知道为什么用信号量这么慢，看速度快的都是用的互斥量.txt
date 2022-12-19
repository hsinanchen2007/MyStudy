#include <semaphore.h>
#include <atomic>
class H2O {
public:
    H2O() {
        sem_init(&osem,0,1);
        sem_init(&hsem,0,2);
        icnt.store(0);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        int cnt = 2;
        sem_wait(&hsem);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        icnt.fetch_add(1);
        if(icnt.compare_exchange_strong(cnt,0))
        {
            sem_post(&osem);
        }  
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&osem);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&hsem);
        sem_post(&hsem);
    }
private:
    sem_t osem,hsem;
    atomic<int> icnt;
};