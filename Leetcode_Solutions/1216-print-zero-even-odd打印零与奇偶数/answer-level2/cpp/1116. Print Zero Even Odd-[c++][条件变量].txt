```c++
class ZeroEvenOdd {
private:
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int x = 1; x <= n; ++x) {
            std::unique_lock<std::mutex> lock(_mu);
            _cv[0].wait(lock, [this]{
                return _flag == 0; // check
            });
            printNumber(0);
            _flag = 2 - (x & 1);
            _cv[_flag].notify_one();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int x = 2; x <= n; x += 2) {
            std::unique_lock<std::mutex> lock(_mu);
            _cv[2].wait(lock, [this]{
                return _flag == 2; // check
            });
            printNumber(x);
            _flag = 0;
            _cv[0].notify_one();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int x = 1; x <= n; x += 2) {
            std::unique_lock<std::mutex> lock(_mu);
            _cv[1].wait(lock, [this]{
                return _flag == 1; // check
            });
            printNumber(x);
            _flag = 0;
            _cv[0].notify_one();
        }
    }
private:
    int _flag = 0;
    std::mutex _mu;
    std::condition_variable _cv[3];
};
```
