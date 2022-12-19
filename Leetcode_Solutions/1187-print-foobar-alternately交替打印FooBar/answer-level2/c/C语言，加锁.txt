typedef struct 
{
    int n;
    pthread_mutex_t lock_1;
    pthread_mutex_t lock_2;
} FooBar;

FooBar* fooBarCreate(int n) 
{
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    pthread_mutex_init(&obj->lock_1, NULL);
    pthread_mutex_init(&obj->lock_2, NULL);
    return obj;
}

void foo(FooBar* obj) 
{
    for (int i = 0; i < obj->n; i++) 
    {
        pthread_mutex_lock(&obj->lock_1);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        pthread_mutex_unlock(&obj->lock_2);
    }
}

void bar(FooBar* obj) 
{
    for (int i = 0; i < obj->n; i++) 
    {
        pthread_mutex_lock(&obj->lock_2);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        pthread_mutex_unlock(&obj->lock_1);
    }
}

void fooBarFree(FooBar* obj) 
{
    free(obj);
}