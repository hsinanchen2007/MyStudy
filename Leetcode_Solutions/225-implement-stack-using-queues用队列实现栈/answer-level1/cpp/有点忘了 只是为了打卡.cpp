### 解题思路
有点忘了 只是为了打卡

### 代码

```cpp
class MyStack {
public:
    queue<int> st;
    /** Initialize your data structure here. */
    MyStack() {
        while(!st.empty())
            st.pop();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        st.push(x);
        int n=st.size();
        while(n>1){
            st.push(st.front());
            st.pop();
            n--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t=st.front();
        st.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return st.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```