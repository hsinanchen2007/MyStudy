## 思路
把每次的最小值（之前最小值和新压入栈元素较小者）都保存在辅助栈中。辅助栈的栈顶元素永远保存当前最小值。
- 如果新压入栈元素小于辅助栈栈顶元素，则将该元素压入辅助栈；
- 否则，再次将栈顶元素压入辅助栈。

### 代码

```cpp
class MinStack {
    stack<int> st;
    stack<int> st_min;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        st.push(x);
        if (!st_min.empty() && st_min.top() < x) {
            st_min.push(st_min.top());
        } else {
            st_min.push(x);
        }        
    }
    
    void pop() {
        st.pop();
        st_min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int min() {
        return st_min.top();
    }
};
```

### 另一种写法
如果当前元素大于栈顶元素，则不压入（节省一定空间），而在上一种方法中则重复压入最小栈栈顶元素（节省弹出时间）。
```c++
class MinStack {
    stack<int> st;
    stack<int> st_min;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        st.push(x);
        if (st_min.empty() || st_min.top() >= x) {
            st_min.push(x);
        }     
    }
    
    void pop() {
        if (st.top() == st_min.top()) st_min.pop();
        st.pop();     
    }
    
    int top() {
        return st.top();
    }
    
    int min() {
        return st_min.top();
    }
};
```
