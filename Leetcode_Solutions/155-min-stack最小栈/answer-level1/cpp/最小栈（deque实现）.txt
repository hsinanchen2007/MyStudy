实在看不懂用内置的<stack>实现栈有什么意思，而且这个都不用模板，很容易。
**解答：**
```
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {       //deque双向列队实现

    }
    
    void push(int x) {
        stack.push_back(x);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        int t_min;
        for(auto s : stack){
            if(s < min){
                min = s;
            }
        }
        t_min = min;
        min = INT_MAX;
        return t_min;
    }
private:
    deque<int> stack;
    int min = INT_MAX;
    
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
