### 解题思路
- 可以采用队列实现
- 采用固定数组空间实现

### 代码

228ms 47.2MB 被95%老哥打败
```cpp
class MovingAverage {
private: 
    int max_size;
    queue<int> myque;// 用带长度得队列存储数据得元素值
    int now_size = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        max_size = size;
    }

    double next(int val) {
        if(myque.size() == max_size) myque.pop();
        else ++now_size;
        myque.push(val);
        queue<int> temp;
        temp = myque;
        double rst;
        while(!temp.empty()){
            rst += temp.front();
            temp.pop();
        }
        return rst/now_size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
```