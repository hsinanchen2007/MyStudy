```
typedef struct {
    // User defined data may be declared here.
    pthread_barrier_t second;
    pthread_barrier_t third;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    pthread_barrier_init(&obj->second, NULL,2);
    pthread_barrier_init(&obj->third, NULL,3);
    // Initialize user defined data here.
    
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    pthread_barrier_wait(&obj->second);
    pthread_barrier_wait(&obj->third);
}

void second(Foo* obj) {
    
    // printSecond() outputs "second". Do not change or remove this line.
    pthread_barrier_wait(&obj->second);
    printSecond();
    pthread_barrier_wait(&obj->third);
}

void third(Foo* obj) {
    
    // printThird() outputs "third". Do not change or remove this line.
    pthread_barrier_wait(&obj->third);
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    pthread_barrier_destroy(&obj->second);
    pthread_barrier_destroy(&obj->third);
    free(obj);
}
```
