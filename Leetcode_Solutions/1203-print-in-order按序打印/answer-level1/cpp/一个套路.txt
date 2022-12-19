执行用时 :
8 ms
, 在所有 C++ 提交中击败了
91.91%
的用户
内存消耗 :
9 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

class Foo {
public:
    Foo() 
        : one_ok_(false),
          two_ok_(false){
        
    }

    void first(function<void()> printFirst) {
    
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        std::lock_guard<std::mutex> lock(mutex_);
        one_ok_ = true;
        cond_.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mutex_);
        cond_.wait(lock, [&](){
            return this->one_ok_;
        });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        two_ok_ = true;
        cond_.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mutex_);
        cond_.wait(lock, [&](){
            return two_ok_;
        });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
    
private:
    std::mutex mutex_;
    std::condition_variable cond_;
    bool one_ok_;
    bool two_ok_;
};