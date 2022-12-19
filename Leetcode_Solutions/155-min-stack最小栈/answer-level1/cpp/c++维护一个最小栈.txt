### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data.push(x);      //维护一个数据栈
        if(Min_stack.empty())
        {
            Min_stack.push(x);
        }
        else
        {
            if(x>Min_stack.top())
            {
                x=Min_stack.top();
            }
            Min_stack.push(x);
        }
    }
    
    void pop() {
        Min_stack.pop();
        data.pop();
    }
    
    int top() {
        int a=data.top();
        return a;
    }
    
    int getMin() {
        return Min_stack.top();//获取栈顶元素即可
    }
    stack<int>data;  //定义一个数据栈
    stack<int>Min_stack;//定义一个最小栈
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