### 解题思路
没什么好解释的

### 代码

```cpp
class MaxQueue {
vector<int>Q;
int front, rear;
public:
    // 初始化队列
    MaxQueue() {
        front = rear =0;
    }
    int max_value() {
        if(front == rear) return -1;
        int max = -1;
        for(auto i : Q) if(max<i) max = i;
        return max;
    }
    
    void push_back(int value) {
        Q.push_back(value);
        rear++;
    }
    int pop_front() {
        if(front == rear) return -1;
        vector<int>::iterator k = Q.begin();
        int F = *k;
        Q.erase(k);
        front++;
        return F;
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