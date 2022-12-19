C代码用不了sem_t，没办法只能用mutex来做。
两个锁，h线程拿t2锁，打印两次后，释放t1锁，给O线程
O线程拿t1锁，打印后，释放t2锁，再等下一个h线程的t1锁释放

```
typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t t1;
    pthread_mutex_t t2;
    int i;
} H2O;

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    
    // Initialize user defined data here.
    pthread_mutex_init(&obj->t1, NULL);
    pthread_mutex_init(&obj->t2, NULL);
    obj->i = 0;
    return obj;
}

void hydrogen(H2O* obj) {
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    pthread_mutex_lock(&obj->t2);
    releaseHydrogen();
    obj->i++;
    if (obj->i == 2) {
        pthread_mutex_unlock(&obj->t1);
        obj->i = 0;
    }
    else
        pthread_mutex_unlock(&obj->t2);
}

void oxygen(H2O* obj) {
    
    // releaseOxygen() outputs "O". Do not change or remove this line.
    pthread_mutex_lock(&obj->t1);
    releaseOxygen();
    
    pthread_mutex_unlock(&obj->t2);
}

void h2oFree(H2O* obj) {
    // User defined data may be cleaned up here.
    free(obj);
}

```
