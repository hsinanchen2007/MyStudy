typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t t1,t2;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
    pthread_mutex_init(&obj->t1,NULL);  
    pthread_mutex_init(&obj->t2,NULL);  

    pthread_mutex_lock(&obj->t1);
    pthread_mutex_lock(&obj->t2);
    
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    pthread_mutex_unlock(&obj->t1);
}

void second(Foo* obj) {
    
    // printSecond() outputs "second". Do not change or remove this line.
    pthread_mutex_lock(&obj->t1);
    printSecond();
    pthread_mutex_unlock(&obj->t2);
}

void third(Foo* obj) {
    
    // printThird() outputs "third". Do not change or remove this line.
     pthread_mutex_lock(&obj->t2);
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
     pthread_mutex_destroy(&obj->t1);
      pthread_mutex_destroy(&obj->t2);
    
}