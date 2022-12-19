### 解题思路
建立一个辅助栈用来存放栈中的最小值，数据栈s_data,辅助栈s_min

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s_data;  // 初始化栈
    stack<int> s_min;   // 初始化辅助栈
    MinStack() {

    }
    
    void push(int x) {
        s_data.push(x);     // 将x压入栈

        // 这里考虑辅助站压入规则
        if(s_min.size() == 0 || x  < s_min.top()){  // 如果数据栈为空或者该元素小于辅助栈最小值，那么直接将该元素压入辅助栈
            // 如果压进去的值比最小值小，那么更新s_min
            s_min.push(x);
        }
        else{
            // 否则复制最小值压入s_min
            s_min.push(s_min.top());
        }

    }
    
    void pop() {
        if(s_data.size() == 0) return;  // 栈为空

        s_min.pop();
        s_data.pop();
    }
    
    int top() {
        return s_data.top();
    }
    
    int min() {
        assert(s_data.size() > 0 && s_min.size() > 0);  // 辅助栈和数据栈不为空
        return s_min.top();
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