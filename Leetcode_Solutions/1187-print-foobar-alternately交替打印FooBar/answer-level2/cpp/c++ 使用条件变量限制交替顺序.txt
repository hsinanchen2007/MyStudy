```
class FooBar {
private:
    int n;
    std::condition_variable con1_;
    std::condition_variable con2_;
    std::atomic<int> count_;
    std::mutex mutex_;

public:
    FooBar(int n) {
        this->n = n;
        count_ = 0;
        con1_.notify_one();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mutex_);
            con1_.wait(lock, [this, i]() {
                // 判断是否符合只执行了一次循环的要求
                return count_ == i;
            });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            count_ = i;
            con2_.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mutex_);
            con2_.wait(lock, [this, i]() {
                // 判断是否符合只执行了一次循环的要求
                return count_ == i;
            });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            // 唤醒con1_
            count_ = i + 1;
            con1_.notify_one();
        }
    }
};
```
