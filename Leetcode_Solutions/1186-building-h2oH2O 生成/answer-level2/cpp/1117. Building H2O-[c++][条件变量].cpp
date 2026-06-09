```c++
class H2O {
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(_muh);
        _cv.wait(lock, [this]{
            return _h < 2;
        });
        _h++;
        releaseHydrogen();
        lock.unlock();
        std::lock_guard guard(_muo);
        if (_h == 2 && _o == 1) {
            _h = 0;
            _o = 0;
            _cv.notify_all();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(_muo);
        _cv.wait(lock, [this]{
            return _o < 1;
        });
        _o++;
        releaseOxygen();
        lock.unlock();
        std::lock_guard guard(_muh);
        if (_h == 2 && _o == 1) {
            _h = 0;
            _o = 0;
            _cv.notify_all();
        }
    }
private:
    int _h = 0;
    int _o = 0;
    std::mutex _muh;
    std::mutex _muo;
    std::condition_variable _cv;
};
```
