### 解题思路
我们只需记住当前最大值出队后，队列里的下一个最大值即可。

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if(maxDeque.empty())return -1;
        return maxDeque.front();
    }
    
    void push_back(int value) {
        while(!maxDeque.empty() && value > maxDeque.back())
        {
            maxDeque.pop_back();
        }
        //此时maxDeque.back()大于等于value，将value插入，保证非单增序列
        maxDeque.push_back(value);  
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty())return -1;
        int res = q.front();
        q.pop();
        if(res == maxDeque.front())  //注意：要判断普通队列的队头是否和双端队列队头一样，一样的话两个队列都要出队！
            maxDeque.pop_front();  //注意：该操作保证了队列的非单增，因为只有当原队列的队首刚好是最大值时，双端队列才需要出队
        return res;
    }
    queue<int> q;  //存储原队列
    deque<int> maxDeque;  //存储最大值
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```