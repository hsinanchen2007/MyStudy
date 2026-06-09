### 解题思路

打印顺序是 0 奇 0 偶  ...... ,这样的 4步一个循环，

出现奇怪报错的同学检查下 zero 函数里的  printNumber 参数是不是填的 0 .

### 代码

```cpp
#include <mutex>
#include <condition_variable>

class ZeroEvenOdd {
private:
    int n;
    int step;
    std::mutex mtx;
    std::condition_variable cv;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->step = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i = 1 ; i <= n;i++)
        {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck,[=](){
                return step == 0 || step == 2;
            });
            printNumber(0);
            step++;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2 ; i <= n;i+=2)
        {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck,[=](){
                return step == 3;
            });
            printNumber(i);
            step = 0;
            cv.notify_all();   
        }     
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1 ; i <= n;i += 2)
        {
            std::unique_lock<std::mutex> lck(mtx);
            cv.wait(lck,[=](){
                return step == 1;
            });
            printNumber(i);
            step = 2;
            cv.notify_all();
        }
    }
};

```