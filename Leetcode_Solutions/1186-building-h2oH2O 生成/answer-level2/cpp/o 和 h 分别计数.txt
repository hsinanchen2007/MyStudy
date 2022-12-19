### 解题思路

在 h 数量小于 2 之前，可放行 h线程，
在 o 数量小于 1 之前，可放行 o 线程，
放行后检查总量，如果 h == 2 && o == 1,合成水分子,清空计数器

### 代码

```cpp
class H2O {
private:
    std::mutex mtx;
    std::condition_variable cv;
public:
    int hNum;
    int oNum;

    H2O() {
        hNum = 0;
        oNum = 0;
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck,[=](){
            return hNum < 2;
        });
        hNum++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if(hNum == 2 && oNum == 1){
            hNum = 0;
            oNum = 0;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck,[=](){
            return oNum < 1;
        });
        oNum++;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        if(hNum == 2 && oNum == 1){
            hNum = 0;
            oNum = 0;
        }
        cv.notify_all();
    }
};
```