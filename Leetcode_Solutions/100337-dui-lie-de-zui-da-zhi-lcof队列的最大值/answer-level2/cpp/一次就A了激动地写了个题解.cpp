### 解题思路
此处撰写解题思路
辅助双端队列，用作维护一个可访问栈底的单调栈
### 代码

```cpp
class MaxQueue {
public:
    queue<int> q;
    deque<int> s;
    MaxQueue() {

    }
    
    int max_value() {
        if(q.empty()) return -1;
        return s.back();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!s.empty()&&value>s.front()) s.pop_front();
        s.push_front(value);
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        int temp=q.front();
        q.pop();
        if(temp==s.back()) s.pop_back();
        return temp;
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