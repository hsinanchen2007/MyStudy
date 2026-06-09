### 解题思路
一个存数据st，一个存最小的数据min
需要注意的一点：
 if(min.empty()||x**<=**min.top()) min.push(x);这里一定是“<=”,不是‘<’,也就是说就算重了也要存进去
因为现在不存，将来st中pop时，min也要pop，就会出现st重复的那个数还能pop，而min中因为没有重复的数不能pop了

### 代码

```cpp
class MinStack {
public:
    stack<int> st;
    stack<int> min;
    /** initialize your data structure here. */
    MinStack() {
    } 

    void push(int x) {
        st.push(x);
        if(min.empty()||x<=min.top()) min.push(x);
    }
    
    void pop() {
        if(st.top()==min.top()) min.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
    
       return min.top();
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