### 解题思路

执行用时 :88 ms, 在所有 C++ 提交中击败了5.26%的用户
内存消耗 :15.1 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> ori_stack;
    stack<int> min_stack;
    MinStack() {

    }
    
    void push(int x) {
        ori_stack.push(x);
        if(min_stack.empty() || x < min_stack.top()){
            min_stack.push(x);
        }
        else{
            min_stack.push(min_stack.top());
        }
    }
    
    void pop() {
        ori_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return ori_stack.top();
    }
    
    int min() {
        return min_stack.top();
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