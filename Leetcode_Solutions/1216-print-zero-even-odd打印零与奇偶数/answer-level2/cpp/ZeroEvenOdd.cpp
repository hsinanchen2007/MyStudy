### 解题思路
同大多数大佬一样用mutex+condition variable;
不能把x作函数内循环自增数，会超时。。。。。虽然还不懂为什么，但是略过了
### 代码

```cpp
class ZeroEvenOdd {
private:
public:
    int n;
    std::mutex mutex_;
    std::condition_variable cond_;
    int flag = 0;
    int x = 0;
    ZeroEvenOdd(int n) {
        this->n = n;
    }
    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(x<n){
        std::unique_lock<std::mutex> lock(mutex_);
        cond_.wait(lock,[&](){return (this->flag == 0);});
        printNumber(0);
        ++x;
        if(x&1){flag = 1;cond_.notify_all();}
        else{flag = 2;cond_.notify_all();}
        }
    }
    void even(function<void(int)> printNumber) {
        int count = 2;
        std::unique_lock<std::mutex> lock(mutex_);
        while(count<=n){
        cond_.wait(lock,[&](){
            return (this->flag == 2);
        });
        printNumber(x);
        count+=2;
        flag = 0;
        cond_.notify_all();
        }
    }
    void odd(function<void(int)> printNumber) {
        int count = 1;
        std::unique_lock<std::mutex> lock(mutex_);
        while(count<=n){
        cond_.wait(lock,[&](){
             return (this->flag==1);
        });
        printNumber(count);
        count+=2;
        flag = 0;
        cond_.notify_all();
        }
    }
};
```