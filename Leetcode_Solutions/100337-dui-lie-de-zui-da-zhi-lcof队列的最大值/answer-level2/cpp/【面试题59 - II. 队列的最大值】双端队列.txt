## 思路


### 代码

```cpp
class MaxQueue {
    queue<int> que;
    deque<int> deq; 
public:
    MaxQueue() {

    }
    
    int max_value() {
        return deq.empty() ? -1 : deq.front();
    }
    
    void push_back(int value) {
        que.push(value);
        while (!deq.empty() && value > deq.back()) {
            deq.pop_back();
        } 
        deq.push_back(value);
    }
    
    int pop_front() {
        if (que.empty()) return -1;
        int res = que.front();
        que.pop();
        if (res == deq.front()) deq.pop_front();
        return res;        
    }
};
```