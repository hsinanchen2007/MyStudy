### 解题思路

采用pthread库的mutex 和cond 来解题是最常规最正确的思路了。

### 代码

```c
typedef struct {
    int n;
    int flag;
    pthread_mutex_t g_task_lock;
    pthread_cond_t g_task_cv;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    pthread_mutex_init(&obj->g_task_lock,NULL);
    pthread_cond_init(&obj->g_task_cv,NULL);
    obj->flag = true;
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->g_task_lock);
        if(obj->flag == false){
            pthread_cond_wait(&obj->g_task_cv,&obj->g_task_lock);
        }
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        obj->flag = false;
        pthread_cond_signal(&obj->g_task_cv);
        pthread_mutex_unlock(&obj->g_task_lock);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->g_task_lock);
        if(obj->flag == true){
            pthread_cond_wait(&obj->g_task_cv,&obj->g_task_lock);
        }
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        obj->flag = true;
        pthread_cond_signal(&obj->g_task_cv);
        pthread_mutex_unlock(&obj->g_task_lock);
    }
}

void fooBarFree(FooBar* obj) {
    pthread_mutex_destroy(&obj->g_task_lock);
    pthread_cond_destroy(&obj->g_task_cv);
}
```