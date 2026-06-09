执行用时 :16 ms, 在所有 C++ 提交中击败了54.84% 的用户
内存消耗 :9.1 MB, 在所有 C++ 提交中击败了100.00%的用户

```
class Foo {
public:
    pthread_mutex_t one;
    pthread_mutex_t two;
    Foo() {
        pthread_mutex_init(&one, NULL);
        pthread_mutex_init(&two, NULL);
        pthread_mutex_lock(&one);
        pthread_mutex_lock(&two);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        pthread_mutex_unlock(&one);
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        pthread_mutex_lock(&one);
        printSecond();
        pthread_mutex_unlock(&one);
        pthread_mutex_unlock(&two);
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        pthread_mutex_lock(&two);
        printThird();
        pthread_mutex_unlock(&two);
    }
};
```
