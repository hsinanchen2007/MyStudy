## 思路
把每次的最小值（之前最小值和新压入栈元素较小者）都保存在辅助栈中。辅助栈的栈顶元素永远保存当前最小值。
1. 如果新压入栈元素小于辅助栈栈顶元素，则将该元素压入辅助栈；
2. 否则，再次将栈顶元素压入辅助栈。
## 代码
```c++
class MinStack {
    stack<int> st;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);        
        if (min.empty() || x < min.top()) {
            min.push(x);
        } else {
            min.push(min.top());
        }
    }
    
    void pop() {
        st.pop();
        min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};
```
#### 另一种写法
如果当前元素大于栈顶元素，则不压入（节省一定空间），而在上一种方法中则重复压入最小栈栈顶元素（节省弹出时间）。
```c++
class MinStack {
    stack<int> st;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (minStack.empty() || minStack.top() >= x) {
            minStack.push(x);
        } 
    }
    
    void pop() {
        if (st.top() == minStack.top()) {
            minStack.pop();
        }
        st.pop();       
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
```

