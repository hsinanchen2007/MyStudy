# **用mutex和condition_variable**
```
class ZeroEvenOdd {
private:
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        zero_printed = false;
        odd_printed = false;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(mutex_);
        for(int i = 0;i < n;++i){
            cond_.wait(lock,[&](){
               return !zero_printed; 
            });
            printNumber(0);
            zero_printed = true;
            cond_.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(mutex_);
        for(int i = 2;i <= n;i+=2){
            cond_.wait(lock,[&](){
                if(zero_printed)
                    return odd_printed;
                return false;
            });
            printNumber(i);
            odd_printed = false;
            zero_printed = false;
            cond_.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(mutex_);
        for(int i = 1;i <= n;i+=2){
            cond_.wait(lock,[&](){
                if(zero_printed)
                    return !odd_printed;
                return false;
            });
            printNumber(i);
            odd_printed = true;
            zero_printed = false;
            cond_.notify_all();
        }
    }
private:
    std::mutex mutex_;
    std::condition_variable cond_;
    
    bool odd_printed;
    bool zero_printed;
};
```

