### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
    stack<int> st;
    stack<int> st_min;
public:
    MinStack() {

    }
    
    void push(int x) { //push的时候无论如何都要对st进行一次操作
        st.push(x);
        if (!st_min.empty() && st_min.top() < x) {
            //若st_min中的top元素较小，则重复push一个top，确保在pop之后，min栈的top元素依旧为min
            st_min.push(st_min.top());
        } else {
            st_min.push(x);
            //若x较小则push进入min栈对最小元素进行更换
        }        
    }
    
    void pop() {
        st.pop();
        st_min.pop();//st和min栈都需要Pop
    }
    
    int top() {
        return st.top();
    }
    
    int min() {
        return st_min.top();
    }
};


```