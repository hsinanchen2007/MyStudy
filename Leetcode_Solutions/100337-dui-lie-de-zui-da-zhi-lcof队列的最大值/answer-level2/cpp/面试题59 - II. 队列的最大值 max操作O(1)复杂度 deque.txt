```cpp
// 类似上一题滑动窗口最大值
class MaxQueue {
private:
    queue<int> data;   // 数据队列 queue 
    deque<int> max;    // 单调递减栈，为了栈底可弹出用了deque，栈底保存着data中最大值

public:
    MaxQueue() {

    }
    
    int max_value() {
        if (data.empty())
            return -1;
        return max.front();
    }
    
    void push_back(int value) {
        data.push(value);
        while(!max.empty() && value > max.back())
            max.pop_back();
        max.push_back(value);
    }
    
    int pop_front() {
        if (data.empty()) 
            return -1;
        int val = data.front();
        if (val == max.front())
            max.pop_front();
        data.pop();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```