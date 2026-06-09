互斥量和条件变量可以解决大多数线程同步问题。
本题目是面试常见题目，用一个bool变量判断是打印foo还是bar，配合条件变量解决。
```
class FooBar {
private:
    int n;
    mutex   mutex_;
    bool    foo_turn_;
    condition_variable  cv_;

public:
    FooBar(int n) {
        this->n = n;
        foo_turn_ = true;
        cv_.notify_all();
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex>  lk(mutex_);
        
        for (int i = 0; i < n; i++) {
            cv_.wait(lk, [this] {return foo_turn_; });        
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            
            foo_turn_ = false;
            cv_.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex>  lk(mutex_);
        
        for (int i = 0; i < n; i++) {
            cv_.wait(lk, [this] {return !foo_turn_; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            foo_turn_ = true;
            cv_.notify_all();
        }
    }
};
```
