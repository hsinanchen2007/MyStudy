### 解题思路
此处撰写解题思路

### 代码

```cpp
class MaxQueue {
    deque<int> d; //使用双向队列维护一个单调递减
    queue<int> q; //

public:
    MaxQueue() {

    }
    
    int max_value() {
        if(!d.empty())
        {
            return d.front();//d的头部是最大元素
        } 
        return -1;
    }
    
    void push_back(int value) {
        while(!d.empty() && value > d.back())
        {
            d.pop_back();//如果插入元素大于d的尾部元素，则把d的尾部弹出，
        }
        d.push_back(value);//把元素插入到d的尾部
        q.push(value);//在单向队列中保存插入元素
    }
    
    int pop_front() {
        if(q.empty())
        {
           return -1;//如果单向队列q为空，则队列为空；
        }
        int ans = q.front();//返回队列的头元素；
        q.pop();//单向队列q删除其头元素；
        if(ans == d.front())//如果要删除的元素是d的头元素，则ans是q里的最大元素；
        {
            d.pop_front();//更新d
        }
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