### 解题思路
普通栈加单调栈

### 代码

```c++ []
class MinStack {
public:
    /** initialize your data structure here. */
    // 双栈法(普通栈加单调栈)
    MinStack() {

    }
    
    void push(int x) {
        st.push(x);
        if(mst.empty()) mst.push(x);
        else if(x < mst.top()) mst.push(x);
        else mst.push(mst.top());
    }
    
    void pop() {
        st.pop();
        mst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }

private:
    stack<int> st;
    stack<int> mst;
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