#include<semaphore.h>
class FooBar {
private:
    int n;
    sem_t sem_foo,sem_bar;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&sem_foo,0,0);
        sem_init(&sem_bar,0,1);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            sem_wait(&sem_bar);
        	printFoo();
            sem_post(&sem_foo);
            
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            sem_wait(&sem_foo);
        	printBar();
            sem_post(&sem_bar);
        }
    }
};