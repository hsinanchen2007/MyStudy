### 解题思路
建立辅助栈smin
smin:x<top入x；x>top入top
确保smin.top是最小值

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s,smin;//定义两个栈
    MinStack() {

    }
    //入栈
    void push(int x) {
        s.push(x);
        if(smin.empty()) smin.push(x);//smin空，直接入栈
        else//smin不为空
        {
            if(x<smin.top()) smin.push(x);
            else smin.push(smin.top());
        }
    }
    
    void pop() {
        s.pop();
        smin.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {//返回最小值
        //if(s.empty()) return ??
        int a=smin.top();
        //smin.pop();
        return a;
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