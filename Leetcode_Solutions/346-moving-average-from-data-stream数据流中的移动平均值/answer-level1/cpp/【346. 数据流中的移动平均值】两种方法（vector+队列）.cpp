## 思路一：使用vector
### 代码
缺点：浪费空间，vector之前的空间被浪费。
```c++
class MovingAverage {
    vector<int> data;
    int windowSize;
    int pos;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        windowSize = size;
        pos = -1;
    }
    
    double next(int val) {
        data.push_back(val);
        ++pos;
        int sum = 0, k = 0;        
        for (int i = pos; i >= 0 && k < windowSize; --i) {
            sum += data[i];
            ++k;
        }
        return sum * 1.0 / k;
    }
};
```

## 思路二：使用队列
### 代码
```c++
class MovingAverage {
    queue<int> que;
    int windowSize;
    double sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        windowSize = size;        
        sum = 0;
    }
    
    double next(int val) {
        if (que.size() < windowSize) {
            sum += val;
            que.push(val);
        } else {
            sum -= que.front();
            que.pop();
            sum += val;
            que.push(val);
        }
        return sum / que.size();
    }
};
```

