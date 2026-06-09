### 解题思路
用一个栈存储数据，另外维护一个最小堆，当数据小于等于最小堆的堆顶，就插入，当`Pop`的数据与堆顶一样的时候，就`pop` 堆顶元素。

**时间复杂度**：插入的时间复杂度是`$O(logn)$`，弹出的时间复杂度是 `$O(1)$`。
**空间复杂度**：由于使用了另外一个堆来存储数据，空间复杂度为 `$O(1)$`。

看了其他解法，比较常见是辅助栈，还有链表解法。

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    priority_queue<int, vector<int>, greater<int> > min_queue;
    MinStack() {
    }

    void push(int x) {
        if(min_queue.empty()){
            min_queue.push(x);
        }else if(x <= min_queue.top()){
            min_queue.push(x);
        }
        s.push(x);
    }
    
    void pop() {
        if(s.top() == min_queue.top()){
            min_queue.pop();
        }
        s.pop();
    }
    
    int top() {
        int output = s.top();
        return output;
    }
    
    int getMin() {
        int output = min_queue.top();
        return output;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```