### 解题思路
参考官方解法中的辅助双端队列的方法，进行实现的。

### 代码

```cpp
class MaxQueue {
private:
    queue<int> que;
    deque<int> deq;
public:
    MaxQueue() {
        ;
    }
    
    int max_value() {
        if(que.empty()) return -1;
        return deq.front();
    }
    
    void push_back(int value) {
        que.push(value);
        while(true){
            if(deq.empty()){
                deq.push_back(value);
                break;
            }
            if(deq.back() < value){
                deq.pop_back();
            }else{
                deq.push_back(value);
                break;
            }
        }
    }
    
    int pop_front() {
        if(que.empty()) return -1;
        int temp = que.front();
        que.pop();
        if(temp == deq.front()) deq.pop_front();
        return temp;
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