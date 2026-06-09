创建两把互斥锁，两个线程互相加锁和解锁。

```

typedef struct {
    int n;
    pthread_mutex_t t1, t2;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    pthread_mutex_init(&obj->t1, NULL);
    pthread_mutex_init(&obj->t2, NULL);
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        
        // printFoo() outputs "foo". Do not change or remove this line.
        pthread_mutex_lock(&obj->t1);
        printFoo();
        pthread_mutex_unlock(&obj->t2);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        
        // printBar() outputs "bar". Do not change or remove this line.
        pthread_mutex_lock(&obj->t2);
        printBar();
        pthread_mutex_unlock(&obj->t1);
    }
}

void fooBarFree(FooBar* obj) {
    if(obj)
    {
        pthread_mutex_destroy(&obj->t1);
        pthread_mutex_destroy(&obj->t2);
        free(obj);
        obj = NULL;
    }
}
```
