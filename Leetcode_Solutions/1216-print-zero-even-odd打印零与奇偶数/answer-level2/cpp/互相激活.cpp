典型的线程同步, zero  odd even 三者互相激活.
偶数时 zero 激活 even,奇数时 zero 激活 odd
odd 会激活zero
even会激活zero

```
class ZeroEvenOdd {
private:
    int n;
    pthread_mutex_t lockZero;
    pthread_mutex_t lockOdd;
    pthread_mutex_t lockEven;
    
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        pthread_mutex_init(&lockZero, NULL);
        pthread_mutex_init(&lockOdd, NULL);
        pthread_mutex_init(&lockEven, NULL);
        pthread_mutex_lock(&lockOdd);
        pthread_mutex_lock(&lockEven);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {        
       
        for(int i = 1;i <= this->n; ++i){
            pthread_mutex_lock(&lockZero);
            printNumber(0);
            if(i%2){
                pthread_mutex_unlock(&lockOdd);
            }else{
                pthread_mutex_unlock(&lockEven);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <= this->n; i += 2){
            pthread_mutex_lock(&lockEven);
            printNumber(i);
            pthread_mutex_unlock(&lockZero);
        }         
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <= this->n ; i += 2){
            pthread_mutex_lock(&lockOdd);
            printNumber(i);
            pthread_mutex_unlock(&lockZero);
        }
    }

};
```
```