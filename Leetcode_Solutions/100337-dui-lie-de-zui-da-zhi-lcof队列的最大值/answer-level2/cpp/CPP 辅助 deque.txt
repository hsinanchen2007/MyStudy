### 解题思路

辅助 deque, 如果压入的值比deque 后端的值大， 则 pop_back()

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(q2.empty()) return -1;
        return q2.front();
    }
    
    void push_back(int value) {
        q1.push(value);
        while(!q2.empty() && value > q2.back())
            q2.pop_back();
        q2.push_back(value);
    }
    
    int pop_front() {
        if(q1.empty()) return -1;
        int res = q1.front();
        q1.pop();
        if(res == q2.front()){
            q2.pop_front();
        }
        return res;
    }

private:
    queue<int> q1;
    deque<int> q2;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```