互斥信号量同步即可

```
class FooBar {
private:
    int n;
    pthread_mutex_t mutex1;
    pthread_mutex_t mutex2;
    
public:
    FooBar(int n) {
        this->n = n;
        pthread_mutex_init(&mutex1, NULL);
        pthread_mutex_init(&mutex2, NULL);
        pthread_mutex_lock(&mutex2);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
        	// printFoo() outputs "foo". Do not change or remove this line.
            pthread_mutex_lock(&mutex1);
        	printFoo();
            pthread_mutex_unlock(&mutex2);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
        	// printBar() outputs "bar". Do not change or remove this line.
            pthread_mutex_lock(&mutex2);
        	printBar();
            pthread_mutex_unlock(&mutex1);
        }
    }
};
```