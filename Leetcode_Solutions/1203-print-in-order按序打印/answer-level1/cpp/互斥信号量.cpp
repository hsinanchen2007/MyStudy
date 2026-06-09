1. 通过上锁对线程进行同步即可。
```
class Foo {
public:
    Foo() {
        pthread_mutex_init(&mutex2, NULL);
        pthread_mutex_init(&mutex3, NULL);
        pthread_mutex_lock(&mutex2);
        pthread_mutex_lock(&mutex3);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        pthread_mutex_unlock(&mutex2);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&mutex2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        pthread_mutex_unlock(&mutex3);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&mutex3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    pthread_mutex_t mutex2;
    pthread_mutex_t mutex3;
};
```