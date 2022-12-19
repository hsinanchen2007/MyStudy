### 解题思路
双端队列辅助。

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {
        //辅助队列
    }
    
    int max_value() {
        return maxQ.empty()?-1: maxQ.front();
    }
    
    void push_back(int value) {
        numsQ.push(value);

        while(!maxQ.empty() && value > maxQ.back())
        {
            maxQ.pop_back();
        }

        maxQ.push_back(value);
    }
    
    int pop_front() {
        
        if(numsQ.empty()) return -1;

        int fr = numsQ.front();
        numsQ.pop();

        if(maxQ.front() == fr)
        {
            maxQ.pop_front();
        }

        return fr;
    }

    std::queue<int> numsQ;
    std::deque<int> maxQ;
};
```