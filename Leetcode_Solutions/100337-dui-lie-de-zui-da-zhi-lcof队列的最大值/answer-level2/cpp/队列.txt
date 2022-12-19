### 解题思路
如果只用一个max记录最大值，会在队列pop的时候，找不到下一个最大值是多少，因此想到用一个队列来记录最大值
### 代码

```cpp
class MaxQueue {
private:
    queue<int> q;
    deque<int> d;
     
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(q.empty()) return -1;
        return d.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!d.empty()&&d.back() < value){
            d.pop_back();
        }
        d.push_back(value);
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        int res = q.front();
        if(res == d.front()){
            d.pop_front();
        }
        q.pop();
        return res;
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