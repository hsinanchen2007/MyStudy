## 思路
**注意：在popMax重新入栈元素时，直接调用push会同时更新最大值栈，如果调用st.push()则不会更新新的最大值**
### 代码
```c++
class MaxStack {
    stack<int> st;
    stack<int> maxStack;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (maxStack.empty() || x >= maxStack.top()) {
            maxStack.push(x);
        } 
    }
    
    int pop() {
        int t = st.top();
        if (t == maxStack.top()) {
            maxStack.pop();
        }
        st.pop();
        return t;       
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return maxStack.top();
    }
    
    int popMax() {
        int t = maxStack.top();   
        maxStack.pop();   
        stack<int> tmp;
        while (st.top() != t) {
            tmp.push(st.top());
            st.pop();
        }
        st.pop();
        while (!tmp.empty()) {
            push(tmp.top());//调用push，而不是st.push()
            tmp.pop();
        }
        return t;
    }
};
```
