### 解题思路
此处撰写解题思路

### 代码

```cpp
class Foo {
public:
    Foo():one_ok_(false), two_ok_(false) {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        one_ok_ = true;
        cond.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mutex);
        cond.wait(lock, [&](){
        return this->one_ok_;
        });



        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        two_ok_ = true;
        cond.notify_all();
    }

    void third(function<void()> printThird) {
        
         std::unique_lock<std::mutex> lock(mutex);
        cond.wait(lock, [&](){
        return this->two_ok_;
        });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
     std::mutex mutex; 
     std::condition_variable cond; 
     bool one_ok_; 
     bool two_ok_; 
};
```