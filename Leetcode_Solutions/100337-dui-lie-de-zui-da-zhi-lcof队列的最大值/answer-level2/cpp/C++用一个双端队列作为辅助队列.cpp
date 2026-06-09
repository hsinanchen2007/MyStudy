### 解题思路
此处撰写解题思路

### 代码

```cpp
class MaxQueue {
private:
    queue<int> q;
    deque<int> q_max;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(q_max.empty()) return -1;
        return q_max.front();
    }
    
    void push_back(int value) {
        q.push(value);
        if(q_max.empty() || value<=q_max.back()) q_max.push_back(value);
        else
        {
            while(!q_max.empty() && value > q_max.back())
            {
                q_max.pop_back();
            } 
            q_max.push_back(value);
        }
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        if(q.front()==q_max.front())
        {
            q_max.pop_front();
        }
        int front=q.front();
        q.pop();
        return front;
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