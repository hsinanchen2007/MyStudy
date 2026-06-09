### 主要思想
队列的性质使得：在当前最大值MAX前面的数（比MAX小）不影响结果（先于MAX弹出队列），在MAX后的数会影响结果（当MAX弹出后，MAX值就从后面的数选择）。
使用双端队列deque（辅助队列）来维护一个单调递减的队列，能O(1)返回MAX（位于deque的队首front），且直到弹出MAX后（deque pop_front)，deque的front依然是当前MAX。

### 代码

```cpp
class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(q.empty())   return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while(!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int front = q.front();
        if(front == d.front())
            d.pop_front();
        q.pop();
        return front;
    }
};
![c.png](https://pic.leetcode-cn.com/3ba094832789aab0f55fa23783f980ffa3c0903e8f186a167f79ba0b27a2efc3-c.png)

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```