### 解题思路
维护一个队内元素尽可能为最大值（呈递减）的双端队列

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(q.empty())
            return -1;
        return Max.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(Max.size()&&Max.back()<=value)
            Max.pop_back();
        Max.push_back(value);  
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int ret=q.front();
        q.pop();
        if(ret==Max.front())
            Max.pop_front();
        return ret;

    }
private:
    queue<int> q;
    deque<int> Max;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```