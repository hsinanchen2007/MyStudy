
找[博客](https://blog.csdn.net/linfeng999/article/details/6291824?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-9&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-9)学的信号量函数的用法，尝试着用了一下。
原理很容易，就是确保各个线程操作的原子性，然后再考虑一下三者的顺序关系即可，信号量（这里用互斥量就可以），条件变量都可以很容易实现。
```
#include <semaphore.h>
class Foo {
    
protected:
    sem_t firstJobDone;
    sem_t secondJobDone;
public:
    Foo() {
      sem_init(&firstJobDone,0,0);
      //第一个参数为指向信号量结构的一个指针；第二个参数意思是是否用于进程间共享，不为０时此信号量在进程间共享，否则只能为当前进程的所有线程共享；value给出了信号量的初始值0。　　
      sem_init(&secondJobDone,0,0);
      
    }

    void first(function<void()> printFirst) {
        
        printFirst();
        sem_post(&firstJobDone);

    }

    void second(function<void()> printSecond) {
       
        sem_wait(&firstJobDone);
        printSecond();
        sem_post(&secondJobDone);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondJobDone);
        printThird();
    }
};
```
