### 解题思路
- 核心要点：用一个queue存队列，用一个deque作为辅助队列，队首始终是queue的最大值
- 注意：入队操作是关键，要检查deque队尾是否小于要插入的value，如是则要把队尾弹出，直到队尾不小于要插入的value
- 执行用时 :324 ms, 在所有 C++ 提交中击败了5.01%的用户
- 内存消耗 :49 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class MaxQueue {
    queue<int>mq;
    deque<int>dq;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(mq.empty())return -1;
        return dq.front();
    }
    
    void push_back(int value) {
        while(!dq.empty()&&dq.back()<value)dq.pop_back();
        dq.push_back(value);
        mq.push(value);
    }
    
    int pop_front() {
        if(mq.empty())return -1;
        int result=mq.front();
        mq.pop();
        if(result==dq.front()){      
            dq.pop_front();
        }
        return result;
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