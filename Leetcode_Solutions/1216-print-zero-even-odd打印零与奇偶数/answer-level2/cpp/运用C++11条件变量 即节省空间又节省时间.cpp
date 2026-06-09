### 解题思路
时间超过97.25% 空间超过100% 因为C++11天然提供wait的断言,所以通过两个bool值的状态转移我们可以轻松实现同步

### 代码

```cpp
class ZeroEvenOdd {
private:
    int n;
    std::condition_variable g_cv;
    std::mutex mt;
    bool ze,other;
public:
    ZeroEvenOdd(int n) : g_cv(), mt(), ze(false), other(true){
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i = 1; i <= n; ++i){
            std::unique_lock<std::mutex> lk(mt);
            g_cv.wait(lk, [=](){return !ze && other;});
            printNumber(0);
            if(i&1)ze = true;
            else other = false;
            g_cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <= n; i+=2){
            std::unique_lock<std::mutex> lk(mt);
            g_cv.wait(lk,[=](){return !ze && !other;});
            printNumber(i);
            ze = false;
            other = true;
            g_cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i+=2){
            std::unique_lock<std::mutex> lk(mt);
            g_cv.wait(lk, [=](){return ze && other;});
            printNumber(i);
            ze = false;
            g_cv.notify_all();
        }
    }
};
```