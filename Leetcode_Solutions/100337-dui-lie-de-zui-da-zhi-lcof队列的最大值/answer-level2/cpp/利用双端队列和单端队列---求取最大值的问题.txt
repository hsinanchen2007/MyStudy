### 解题思路
此处撰写解题思路

### 代码

```cpp
//题目理解：上：执行函数  下：给的数值
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() 
    {
        return que.empty()?-1:dq.front();
    }
    
    void push_back(int value) 
    {
        que.push(value);
        while(!dq.empty()&&dq.back()<value)   //重要
            dq.pop_back();
        dq.push_back(value);
    }
    
    int pop_front() 
    {
        if(que.empty())
            return -1;
        int t=que.front();
        que.pop();
        if(t==dq.front())
            dq.pop_front();
        return t;
    }
private:
    queue<int> que;
    deque<int> dq;
};


/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```