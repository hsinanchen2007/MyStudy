#include <semaphore.h>
class H2O {
public:
    H2O() {
        sem_init(&h_limit, 0, 2);
        sem_init(&o_limit, 0, 1);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        sem_wait(&h_limit);
        releaseHydrogen();
        count_h++;
        if(count_h == 2){
          count_h = 0;
          sem_post(&o_limit);
        }   
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        sem_wait(&o_limit);
        releaseOxygen();
        sem_post(&h_limit);
        sem_post(&h_limit);
    }
private:
    int count_h = 0;
    sem_t h_limit;
    sem_t o_limit;
    
};