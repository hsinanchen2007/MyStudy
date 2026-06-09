### 解题思路
> “当一个元素进入队列的时候，它前面所有比它小的元素就不会再对答案产生影响。”

### 代码

```cpp
class MaxQueue {
public:
    queue<int> *head = nullptr;         //用于存放队列元素
    deque<int> *sortedNum = nullptr;    //用于存放排序后的元素

    MaxQueue() {
        head = new queue<int>;
        sortedNum = new deque<int>;
    }
    
    int max_value() {
        if(sortedNum->empty()) return -1;
        return sortedNum->front();
    }
    
    void push_back(int value) {
        while((!sortedNum->empty()) && sortedNum->back() < value){
            sortedNum->pop_back();
        }
        sortedNum->push_back(value);
        head->push(value);
    }
    
    int pop_front() {
        if(head->empty()) return -1;
        else{
            int val = head->front();
            if(val == sortedNum->front()) sortedNum->pop_front();
            head->pop();
            return val;
        }
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



