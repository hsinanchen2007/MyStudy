```
class MaxQueue {
public:
    queue<int> que;
    deque<int> deq;
    MaxQueue() {
        
    }
    int max_value() {
        if (deq.empty()) {
            return -1;
        }
        return deq.front();
    }
    
    void push_back(int value) {
        while (!deq.empty() && deq.back() < value) {//反正是要插入的，但是如果前面的值小于当前就要去掉
            deq.pop_back();
        }
        deq.push_back(value);
        que.push(value);
    }//插入的时候就不要考虑删除时候的事情
    
    int pop_front() {
        if (que.empty()) {
            return -1;
        }
        int ans = que.front();
        if (deq.front() == ans) {
            deq.pop_front();
        }
        que.pop();
        return ans;
    }
};
```
