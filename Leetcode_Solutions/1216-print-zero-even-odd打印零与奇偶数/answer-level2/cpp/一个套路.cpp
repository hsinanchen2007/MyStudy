执行用时 :
8 ms
, 在所有 C++ 提交中击败了
90.74%
的用户
内存消耗 :
9.3 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

class ZeroEvenOdd {
private:
    int n;

public:
    ZeroEvenOdd(int n) 
        : zero_flag_(true),
          index_(1){
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(true){
            std::unique_lock<std::mutex> lock(mutex_);
            cond_.wait(lock, [&](){return (index_>n) or zero_flag_;});
            if(index_ > n) return;
            printNumber(0);
            zero_flag_ = false;
            cond_.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(true){
            std::unique_lock<std::mutex> lock(mutex_);
            cond_.wait(lock, [&](){return (index_>n) or (!zero_flag_ and !(index_&1));});
            if(index_ > n) return;
            printNumber(index_++);
            zero_flag_ = true;
            cond_.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(true){
            std::unique_lock<std::mutex> lock(mutex_);
            cond_.wait(lock, [&](){return (index_>n) or (!zero_flag_ and (index_&1));});
            if(index_ > n) return;
            printNumber(index_++);
            zero_flag_ = true;
            cond_.notify_all();
        }
    }
private:
    bool zero_flag_;
    int index_;
    std::mutex mutex_;
    std::condition_variable cond_;
};