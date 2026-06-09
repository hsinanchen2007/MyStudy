### 解题思路
双向队列

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() 
    {
    }
    
    int max_value() 
    {
        if(deque_max_num.empty()) return -1;
        return deque_max_num.front();
    }
    
    void push_back(int value) 
    {
        while((!deque_max_num.empty())&&value>deque_max_num.back())
        {
            deque_max_num.pop_back();
        }
        queue_num.push(value);
        deque_max_num.push_back(value);
    }
    
    int pop_front() 
    {
        if(deque_max_num.empty()||queue_num.empty()) return -1;
        int temp=queue_num.front();
        if(temp==deque_max_num.front()) deque_max_num.pop_front();
        queue_num.pop();
        return temp;
    }

private:
    queue<int > queue_num;
    deque<int > deque_max_num;

};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```