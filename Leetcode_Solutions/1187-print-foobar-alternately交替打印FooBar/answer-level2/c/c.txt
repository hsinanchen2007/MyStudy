### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int n;
  pthread_mutex_t first_lock;
  pthread_mutex_t next_lock;  
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    pthread_mutex_init(&obj->first_lock,NULL);
    pthread_mutex_init(&obj->next_lock,NULL);
    pthread_mutex_lock(&obj->next_lock);
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->first_lock);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        pthread_mutex_unlock(&obj->next_lock);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->next_lock);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        pthread_mutex_unlock(&obj->first_lock);
    }
}

void fooBarFree(FooBar* obj) {
    free(obj);
}
```