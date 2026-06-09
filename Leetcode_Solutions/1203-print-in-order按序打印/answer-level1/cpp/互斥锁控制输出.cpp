
使用互斥锁控制

`
class Foo {
private:
    pthread_mutex_t mutex_one;
    pthread_mutex_t mutex_two;
    pthread_mutex_t mutex_three;
public:
    Foo() {
    pthread_mutex_init(&mutex_one,NULL);
    pthread_mutex_init(&mutex_two,NULL);
    pthread_mutex_init(&mutex_three,NULL);
    pthread_mutex_lock(&mutex_two);
    pthread_mutex_lock(&mutex_three);
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        pthread_mutex_lock(&mutex_one);
        printFirst();
        pthread_mutex_unlock(&mutex_two);
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        pthread_mutex_lock(&mutex_two);
        printSecond();
        pthread_mutex_unlock(&mutex_three);
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        pthread_mutex_lock(&mutex_three);
        printThird();
        pthread_mutex_unlock(&mutex_one);
    }
};`