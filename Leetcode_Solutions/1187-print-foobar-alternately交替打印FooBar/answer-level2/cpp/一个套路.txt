执行用时 :
12 ms
, 在所有 C++ 提交中击败了
88.61%
的用户
内存消耗 :
10.4 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

class FooBar {
private:
    int n;

public:
    FooBar(int n) 
        : foo_true_(true){
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	std::unique_lock<std::mutex> lock(mutex_);
            cond_.wait(lock, [&](){return foo_true_;});
            printFoo();
            foo_true_ = false;
            cond_.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	std::unique_lock<std::mutex> lock(mutex_);
            cond_.wait(lock, [&](){return !foo_true_;});
            printBar();
            foo_true_ = true;
            cond_.notify_one();
        }
    }
private:
    bool foo_true_;
    std::mutex mutex_;
    std::condition_variable cond_;
};