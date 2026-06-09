### 解题思路
通过双端队列构建一个单调递减（允许重复）的序列，遇见较大的value就从后往前逐个删去比它小的项，直到满足递减序列的条件
### 代码

```cpp
class MaxQueue {
public:
    queue<int>q;
    deque<int>d;
    MaxQueue() {
    }
    
    int max_value() {
        if(d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while(!d.empty()&&value>=d.back())
            d.pop_back();
        q.push(value);
        d.push_back(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        if(q.front()==d.front())
            d.pop_front(); 
        int temp=q.front();
        q.pop();
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