### 解题思路


### 代码

```cpp
class H2O {
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [this] {return num_h < 2;});
        releaseHydrogen();
        num_h++;
        cv.notify_all();
                               
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [this] {return num_h == 2;});
        releaseOxygen();
        num_h = 0;
        cv.notify_all();        
    }
    int num_h = 0;
    std::mutex m;
    std::condition_variable cv;
};
```