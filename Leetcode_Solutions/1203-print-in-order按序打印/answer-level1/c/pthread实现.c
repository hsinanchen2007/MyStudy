代码如下：
```
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>

class Foo {

private:
    int status = 1;
    pthread_mutex_t mutex;
    pthread_cond_t cond;

public:
    Foo() {
        pthread_mutex_init(&mutex, NULL);
        pthread_cond_init(&cond, NULL);
    }
    
    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        status = 2;
        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&mutex);
    
    }

    void second(function<void()> printSecond) {
        struct timeval timeNow;
        struct timespec timedOut;

        pthread_mutex_lock(&mutex);
        while(status != 2) {
            gettimeofday(&timeNow, NULL);
            timedOut.tv_sec = timeNow.tv_sec;
            timedOut.tv_nsec = timeNow.tv_usec * 10;
            pthread_cond_timedwait(&cond, &mutex, &timedOut);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        status = 3;
        pthread_mutex_unlock(&mutex);
    }

    void third(function<void()> printThird) {
        struct timeval timeNow;
        struct timespec timedOut;

        pthread_mutex_lock(&mutex);
        while(status != 3) {
            gettimeofday(&timeNow, NULL);
            timedOut.tv_sec = timeNow.tv_sec;
            timedOut.tv_nsec = timeNow.tv_usec * 10;
            pthread_cond_timedwait(&cond, &mutex, &timedOut);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        status = 0;
        pthread_mutex_unlock(&mutex);
    }
};
```
