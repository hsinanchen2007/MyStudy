### 解题思路

list保存窗口元素位置

sum记录窗口总和

### 代码

```cpp
class MovingAverage {
private:
    vector<int> window;
    int sum = 0;
    int size = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if (this->size == 0) return 0;
        window.push_back(val);
        sum += val;

        while (window.size() > this->size){
            sum -= window.front();
            window.erase(window.begin());
        }
        return (double)sum / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
```