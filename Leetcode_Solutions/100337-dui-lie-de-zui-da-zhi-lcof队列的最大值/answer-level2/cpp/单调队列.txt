

### 代码

```cpp
class MaxQueue {
    queue<int> data;
    deque<int> maxData;
public:
    MaxQueue() {
    }
    
    int max_value() {
        return data.size() == 0?-1:maxData.front();
    }
    
    void push_back(int value) {
        data.push(value);

        while(!maxData.empty() && value > maxData.back())
            maxData.pop_back();
        maxData.push_back(value);
    }
    
    int pop_front() {
        if(data.size() == 0)
            return -1;

        int value = data.front();
        data.pop();

        if(maxData.front() == value)
            maxData.pop_front();

        return value;
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