### 解题思路
此处撰写解题思路

### 代码

```cpp
#include<stack>
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(data.empty())
        {
            //第一次压栈
            data.push(x);
            minData.push(x);
        }
        else
        {
            //当前data栈不空，则minData栈也不空
            data.push(x);
            if(x < minData.top())
            {
                //待压入数据比minData的栈顶还小，压栈
                minData.push(x);
            }
            else
            {
                //否则，继续压入minData的栈顶
                minData.push(minData.top());
            }
        }
    }
    
    void pop() {
        if(!data.empty())
        {
            //同时出栈
            data.pop();
            minData.pop();
        }
        return;
    }
    
    int top() {
        if(!data.empty())return data.top();
        return -1;
    }
    
    int min() {
        if(!minData.empty())return minData.top();
        return -1;
    }
    stack<int> data, minData;  //两个栈，一个是数据栈，一个是辅助栈
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