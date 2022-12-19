在queue出队中，我们需要尽可能快的获得最大值，是对本题的优化点，所以需要一个deque来空间换时间！
设计原则：若deque中的队尾元素小于当前元素，则deque出队即可，这样每次deque维护的是pop_front这一阶段的最大值。

```cpp
class MaxQueue {
private:
    // deque 保存下一个最大值
    // queue 保存正常数据流
    queue<int> q;
    deque<int> dq;
public:
    MaxQueue() {

    }
    
    int max_value() {
        return !dq.empty() ? dq.front() : -1;
    }
    
    void push_back(int value) {
        q.push(value);
        while(!dq.empty() && dq.back()<value) {
            dq.pop_back();
        }
        dq.push_back(value);
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        if(q.front() == dq.front()) {
            dq.pop_front();
        }
        int res = q.front();
        q.pop();
        return res;
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