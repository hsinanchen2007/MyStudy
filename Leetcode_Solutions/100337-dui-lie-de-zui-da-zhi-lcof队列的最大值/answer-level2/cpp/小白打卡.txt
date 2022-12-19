### 解题思路
此处撰写解题思路

### 代码

```cpp
class MaxQueue {
private:
        queue<int> cur_q;
        deque<int> max_d;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(max_d.empty())
            return -1;
        return max_d.front();
    }
    
    void push_back(int value) {
        while(!max_d.empty() && value>max_d.back()){
            max_d.pop_back();
        }     
        max_d.push_back(value);
        cur_q.push(value);
    }
    
    int pop_front() {
        if(cur_q.empty())
            return -1;
        int ans=cur_q.front();
        if(ans==max_d.front())
            max_d.pop_front();
        cur_q.pop();
        return ans;
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