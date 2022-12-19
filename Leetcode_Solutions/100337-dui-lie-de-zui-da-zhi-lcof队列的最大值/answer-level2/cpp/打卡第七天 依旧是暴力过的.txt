### 解题思路
此处撰写解题思路

### 代码

```cpp
class MaxQueue {
public:
    
    int a[5000];
    int front=0,rear=-1;
    MaxQueue() {
 
    }
    
    int max_value() {
        
        if(rear-front==-1) return -1;
        int maxn=0;
        for(int i=front;i<=rear;i++){
            maxn=max(a[i],maxn);
            
        }
        return maxn;
    
    }
    
    void push_back(int value) {
        ++rear;
        a[rear]=value;
    }
    
    int pop_front() {
        if(rear-front==-1) return -1;
        ++front;
        return a[front-1];

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