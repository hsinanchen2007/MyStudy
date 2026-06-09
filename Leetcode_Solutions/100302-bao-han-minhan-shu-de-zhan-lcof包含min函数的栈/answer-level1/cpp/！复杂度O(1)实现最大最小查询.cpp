### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> st_min;//最小栈，保存出现每一个st值时候的最小值；
    MinStack() {

    }
    
    void push(int x) {
        st.push(x);
        if (st_min.size()==0) st_min.push(x);
        else if (x<st_min.top()) st_min.push(x);//如果新进的x是最小，就把它压入最小栈
        else if (x>= st_min.top()) st_min.push(st_min.top());//如果不是最小的，就把最小栈的栈顶重复压入
        return; 
    }
    
    void pop() {
        st.pop();
        st_min.pop();
        return;
    }
    
    int top() {
        return st.top();
    }
    
    int min() {
        return st_min.top();
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