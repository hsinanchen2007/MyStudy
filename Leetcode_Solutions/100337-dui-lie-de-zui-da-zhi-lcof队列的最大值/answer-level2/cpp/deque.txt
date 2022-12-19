### 解题思路
deque

### 代码

```cpp
class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(d.empty())
        {
            return -1;
        }
        else
        {
            return d.front();
        }

    }
    
    void push_back(int value) {
        while(!d.empty()&&d.back()<value)
        {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty())
        {
            return -1;
        }
        else
        {
            int tmp=q.front();
            q.pop();
            if(tmp==d.front())
            {
                d.pop_front();
            }
            return tmp;
        }
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