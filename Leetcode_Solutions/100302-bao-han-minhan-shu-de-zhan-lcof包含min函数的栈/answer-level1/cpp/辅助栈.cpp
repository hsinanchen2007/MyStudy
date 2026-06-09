### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> ans;
    stack<int> minans;
    MinStack() {

    }
    
    void push(int x) {
       ans.push(x);
       if(minans.empty() || minans.top()>=x ) minans.push(x);
    }
    
    void pop() {
       if(ans.top()==minans.top())  minans.pop();
       ans.pop();
       return;
    }
    
    int top() {
       return ans.top();
    }
    
    int min() {
       return minans.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```