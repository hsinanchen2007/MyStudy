### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
private:
    stack<int> stack1;
    stack<int> stack2; 

public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(stack2.empty()){
            stack2.push(x);
        }
        else{
            int t=stack2.top();
            stack2.push(x<t?x:t);
        }
        stack1.push(x);
    }
    
    void pop() {
        stack1.pop();
        stack2.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
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