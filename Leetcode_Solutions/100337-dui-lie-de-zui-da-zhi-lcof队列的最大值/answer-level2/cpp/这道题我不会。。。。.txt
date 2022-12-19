### 解题思路
参考：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-ii-dui-lie-de-zui-da-zhi-by-leetcod/

### 代码

```cpp
class MaxQueue 
{
public:
    queue<int> q1;
    deque<int> q2;//辅助队列用于存储q1中当前所有数字的最大值
    MaxQueue() 
    {
    }
    
    int max_value() 
    {
        if(q2.empty())
        {
            return -1;
        }
        return q2.front();
    }
    
    void push_back(int value) 
    {
        while((!q2.empty()) && (q2.back() < value))
        {
            q2.pop_back();
        }
        q1.push(value);
        q2.push_back(value);
   
    }
    
    int pop_front() 
    {
        if(q1.empty())
        {
            return -1;
        }
        int ans = q1.front();
        if(ans == q2.front())
        {
            q2.pop_front();
        }
        q1.pop();
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