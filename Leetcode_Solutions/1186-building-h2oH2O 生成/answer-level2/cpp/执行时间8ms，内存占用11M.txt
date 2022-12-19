```
class H2O {
private:
    size_t _h_n;
    size_t _o_n;
    mutex  _mtx;
    condition_variable _cv;
public:
    H2O() : _h_n(0), _o_n(0) {}

    void hydrogen(function<void()> releaseHydrogen)
    {
        {
            unique_lock<mutex> lock(_mtx);
            _cv.wait(lock, [this]() {
                return _h_n%2 != 0 ||  //已有一个H
                       _h_n == 2*_o_n; //一个H都还没有
            });

            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen();
            ++_h_n;
        }
        _cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen)
    {
        {
            unique_lock<mutex> lock(_mtx);
            _cv.wait(lock, [this]() {
                return _h_n == _o_n*2 + 2;//H已就绪O才能加入
            });
            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen();
            ++_o_n;
        }
        _cv.notify_all();
    }
};
```
