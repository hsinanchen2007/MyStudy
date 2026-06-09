### 解题思路
就是用数组实现队列，一个前指针一个后指针。挺基础的。

### 代码

```cpp
class MaxQueue {
public:
    int Q[10000];
    int front;
    int rear;
    MaxQueue() {
        front=0;
        rear=0;
    }
    
    int max_value() {
        if(front==rear) return -1;
        int ans=0;
        for(int i=front;i<rear;i++)
        {
            ans=max(ans,Q[i]);
        }
        return ans;
    }
    
    void push_back(int value) {
        Q[rear++]=value;
    }
    
    int pop_front() {
        if(front==rear) return -1;
        int t=Q[front++];
        return t;
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