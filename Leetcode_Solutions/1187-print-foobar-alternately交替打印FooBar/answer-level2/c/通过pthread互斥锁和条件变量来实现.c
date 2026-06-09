# 方案一
# 运行结果
执行结果：通过，显示详情，执行用时:172 ms, 在所有 c 提交中击败了，32.43%的用户，内存消耗 :8.7 MB, 在所有 c 提交中击败了100.00%的用户

# 解题思路
核心要点：
1. 用两把互斥锁
2. foo执行完后，释放bar的锁，bar执行完后，释放foo的锁

代码上来看，整体比较简洁，但效率不高

# 代码
```c
typedef struct {
    int n;
    pthread_mutex_t mutex1;  
    pthread_mutex_t mutex2;  
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    pthread_mutex_init(&obj->mutex1, NULL);
    pthread_mutex_init(&obj->mutex2, NULL);
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex1);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        pthread_mutex_unlock(&obj->mutex2);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex2);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        pthread_mutex_unlock(&obj->mutex1);
    }
}

void fooBarFree(FooBar* obj) {
    if (NULL != obj) {}
        pthread_mutex_destroy(&obj->mutex1);
        pthread_mutex_destroy(&obj->mutex2);
        free(obj);
}
```


# 方案二

# 运行结果
![Leetcode.PNG](https://pic.leetcode-cn.com/2aa1226b6ea7450351dc9103f9dc1aebd02235ba168ad2e7bf6c1a76302bb59e-Leetcode.PNG)

# 解题思路
核心要点：
1. 通过pthread_mutex_lock让两个线程互锁。
2. 构造一个判断条件，当不满足判断条件时，通过pthread_cond_wait让线程停在条件变量上，等待另外一个线程唤醒。
3. 判断条件满足后，修改判断条件的值foo打印后，通过pthread_cond_signal()通知bar线程打印。bar打印后，通过pthread_cond_signal()通知foo线程打印。

pthread_cond_wait内部的操作顺序是将线程放到等待队列，之后解锁，等条件满足时进行加锁，再返回。
1. 线程放在等待队列上，解锁
2. 等待 pthread_cond_signal或者pthread_cond_broadcast信号之后去竞争锁
3. 若竞争到互斥索则加锁。

通知函数有pthread_cond_signal和pthread_cond_broadcast，函数的名字已经充分说明了他们之间的区别。


# 代码

```c
typedef struct {
    int n;
    bool flag;
    pthread_mutex_t mutex;  
    pthread_cond_t  cond;  
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    obj->flag = true;
    pthread_mutex_init(&obj->mutex, NULL);
    pthread_cond_init(&obj->cond,NULL);
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex);
        while (false == obj->flag) {
            pthread_cond_wait(&obj->cond,&obj->mutex);
        }
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        obj->flag = false;
        pthread_cond_signal(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex);
        while (true == obj->flag) {
            pthread_cond_wait(&obj->cond,&obj->mutex);
        }
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        obj->flag = true;
        pthread_cond_signal(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

void fooBarFree(FooBar* obj) {
    if (NULL != obj) {}
        pthread_mutex_destroy(&obj->mutex);
        pthread_cond_destroy(&obj->cond);
        free(obj);
}
```

# 方案三
在C++里面可以通过semaphore信号量来实现，sem_init/sem_wait/sem_post，代码会比较简洁。但是在C里面用不了,不知为撒。


# 后记
但这个实现，耗时比较长，需要优化，但我还没有找到优化的方向，如果哪位有比较好的实现，请到下面写一下思路，让我学习一下，谢谢了！