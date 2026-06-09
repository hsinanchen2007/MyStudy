### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
public:
    vector<int> vals;
    vector<int> min_stack;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        vals.push_back(x);
        if(min_stack.empty() || x < min_stack.back())
            min_stack.push_back(x);
        else {
            min_stack.push_back(min_stack.back());
        }
    }
    
    void pop() {
        vals.pop_back();
        min_stack.pop_back();
    }
    
    int top() {
        return vals.back();
    }
    
    int getMin() {
        return min_stack.back();
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