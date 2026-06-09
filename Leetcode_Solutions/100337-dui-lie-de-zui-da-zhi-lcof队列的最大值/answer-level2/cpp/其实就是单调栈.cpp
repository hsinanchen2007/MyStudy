用双端队列实现一个单调栈，其实可以叫单调队列了。
```cpp
class MaxQueue {
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if (dq.empty()) return -1;
        return dq.front();
    }
    
    void push_back(int value) {
        q.emplace(value);
        while (!dq.empty() && value > dq.back()) {
            dq.pop_back();
        }
        dq.emplace_back(value);
    }
    
    int pop_front() {
        if (q.empty()) return -1;
        int front = q.front();
        q.pop();
        if (front == dq.front()) dq.pop_front();
        return front;
    }
private:
    queue<int> q;
    deque<int> dq;
};
```
