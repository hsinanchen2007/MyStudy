### 解题思路
利用辅助双端队列维持一个单调队列，思路类似滑窗中的最大值那道题

### 代码

```cpp
class MaxQueue {
private:
    queue<int> q;
    deque<int> temp;
    
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(temp.empty()) {
            return -1;
        }
        return temp.front();
    }
    
    void push_back(int value) {
        while(!temp.empty() && value > temp.back()) {
            temp.pop_back();
        }
        temp.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty()) {
            return -1;
        }
        if(q.front() == temp.front()) {
            temp.pop_front();
        }
        int ans = q.front();
        q.pop();
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