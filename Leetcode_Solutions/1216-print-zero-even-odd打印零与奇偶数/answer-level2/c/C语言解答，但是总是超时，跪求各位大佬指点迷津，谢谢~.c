typedef struct {
    int n;
    int current;
    bool flag;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} ZeroEvenOdd;

ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) malloc(sizeof(ZeroEvenOdd));
    obj->n = n;
    obj->current = 1;
    obj->flag = false;
    pthread_mutex_init(&obj->mutex, NULL);
    pthread_cond_init(&obj->cond, NULL);
    return obj;
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.

void zero(ZeroEvenOdd* obj) {
    pthread_mutex_lock(&obj->mutex);
    while(obj->flag) {
       pthread_cond_wait(&obj->cond, &obj->mutex);
    }
    obj->flag = true;
    printNumber(0);
    pthread_cond_broadcast(&obj->cond);
    pthread_mutex_unlock(&obj->mutex);
    
    return;
}

void even(ZeroEvenOdd* obj) {
    pthread_mutex_lock(&obj->mutex);
    while((obj->current % 2 != 0) || (!obj->flag)) {
        pthread_cond_wait(&obj->cond, &obj->mutex);
    }
    obj->flag = false;   
    printNumber(obj->current);
    obj->current++;
    pthread_cond_broadcast(&obj->cond);
    pthread_mutex_unlock(&obj->mutex);
    
    return;
}

void odd(ZeroEvenOdd* obj) {
    pthread_mutex_lock(&obj->mutex);
    while((obj->current % 2 == 0) || (!obj->flag)) {
        pthread_cond_wait(&obj->cond, &obj->mutex);
    }
    obj->flag = false;   
    printNumber(obj->current);
    obj->current++;
    pthread_cond_broadcast(&obj->cond);
    pthread_mutex_unlock(&obj->mutex);
    
    return;
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {
    pthread_mutex_destroy(&obj->mutex);
    pthread_cond_destroy(&obj->cond);
    free(obj);
    return;
}