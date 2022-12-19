### 解题思路
定义一个普通队列进行进入和弹出数据，一个双端队列辅助保存最大值
- 队列最大值：辅助双端队列的头元素
- 入队：将元素存入普通队列，如果当前元素比队尾元素大，则将辅助队列的队尾元素弹出，直到当前元素不大于队尾元素（解释：当前元素比队尾元素大时，队尾元素就不可能是当前队列的最大值）或者辅助队列为空
- 出队：将元素从普通队列弹出，如果当前元素等于辅助队列的队头元素（说明：当前元素是当下队列的最大值），将辅助队列的队头弹出

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(q1.empty())
            return -1;
        else
            return q2.front();
    }
    
    void push_back(int value) {
        q1.push(value);
        while(!q2.empty() && value > q2.back()){
            q2.pop_back();           
        }
        q2.push_back(value);
    }
    
    int pop_front() {
        if(q1.empty())
            return -1;
        int t = q1.front();
        q1.pop();
        if(t == q2.front())
            q2.pop_front();
        return t;
    }
private:
    queue<int> q1;
    deque<int> q2;//作为辅助队列
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```