```cpp
class H2O {
public:
    H2O() {
        cur_h = 0;
        cur_o = 0;
    }
    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        unique_lock lock(m_);
        cond_.wait(lock, [&] {return cur_h < 2;});
        releaseHydrogen();
        cur_h += 1;
        if(cur_h == 2 && cur_o == 1) {
            cur_h = 0;
            cur_o = 0;
        }
        cond_.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        unique_lock lock(m_);
        cond_.wait(lock, [&] {return cur_o == 0;});
        releaseOxygen();
        cur_o += 1;
        if(cur_h == 2 && cur_o == 1){
            cur_h = 0;
            cur_o = 0;
        }
        cond_.notify_all();
    }
private:
    int cur_h;
    int cur_o;
    condition_variable cond_;
    mutex m_;
};
```