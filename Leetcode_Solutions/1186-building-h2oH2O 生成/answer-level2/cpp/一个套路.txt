
执行用时 :
12 ms
, 在所有 C++ 提交中击败了
94.79%
的用户
内存消耗 :
12.9 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

class H2O {
public:
    H2O() 
        : index_(0){
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(mutex_);
        cond_.wait(lock, [&](){return this->index_ < 2;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++index_;
        cond_.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mutex_);
        cond_.wait(lock, [&](){return this->index_ == 2;});
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        index_ = 0;
        cond_.notify_one();
    }
    
private:
    int index_;
    std::mutex mutex_;
    std::condition_variable cond_;
};