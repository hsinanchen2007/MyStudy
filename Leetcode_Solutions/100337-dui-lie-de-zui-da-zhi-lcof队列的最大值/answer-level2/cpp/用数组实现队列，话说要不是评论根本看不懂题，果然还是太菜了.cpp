### 解题思路
此处撰写解题思路

### 代码

```cpp
class MaxQueue {
   vector<int> queue;
     
public:
    MaxQueue() { 
        
        
    }
    
    int max_value() {
        int ans = -1;
        int length = queue.size();
        for(int i=0;i<length;i++)
        {
            ans =max(ans,queue[i]);
            
        }
        return ans;
    }
    
    void push_back(int value) {
        queue.push_back(value);
    }
    
    int pop_front() {
        int ans;
        if(queue.size()==0)
        return -1;
        ans = queue.front();
        queue.erase(queue.begin());
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