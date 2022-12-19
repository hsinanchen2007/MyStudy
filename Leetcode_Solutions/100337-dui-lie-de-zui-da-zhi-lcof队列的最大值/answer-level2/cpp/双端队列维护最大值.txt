### 解题思路
此处撰写解题思路
因为要保证每次int maxValue返回的是一个最大值所以可以采用双端队列来进行维护，建一个<deque>dq,按照从大到小的顺序排列
在执行push函数时，
如果dq为空，则可以直接插入
先判断value与dq.front()的大小，若value > dq.front()，则clear整个队列，再push_back();
若value <= dq.front()则考虑从尾部插入，先进行比较(dq.back() < value)，就pop_back();
知道找到一个值dq.back() > value时，push_back(value);


### 代码

```cpp
#include<queue>
class MaxQueue {
private:
    queue<int> q;
    deque<int> dq;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if(dq.empty()){
            return -1;
        }else{
            return dq.front();
        }
    }
    
    void push_back(int value) {
        q.push(value);
        if(dq.size() == 0){
            dq.push_back(value);
        }else if(value > dq.front()){
            dq.clear();
            dq.push_back(value);
        }else{
            while(dq.back() < value){
                dq.pop_back();
            }
            dq.push_back(value);
        }
    }
    
    int pop_front() {
        if(q.size() == 0){
            return -1;
        }
        int ans = q.front();
        q.pop();
        if(ans == dq.front()){
            dq.pop_front();  
        }
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