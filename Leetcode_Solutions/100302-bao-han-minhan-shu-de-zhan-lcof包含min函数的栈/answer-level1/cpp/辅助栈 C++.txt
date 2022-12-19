利用两个栈，`Stack`存储数据，`minStack`更新当前最小值
```
class MinStack {
    stack<int> Stack;
    stack<int> minStack; //minStack的末尾存储最小值
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        Stack.push(x);
        if(minStack.empty() || minStack.top()>=x)
            minStack.push(x); //minStack为空或最小值大于等于当前输入则入栈
    }
    
    void pop() {
        //删除数据为最小值时，minStack同时pop
        if(minStack.top()==Stack.top()) minStack.pop();
        Stack.pop();
    }
    
    int top() {
        return Stack.top();
    }
    
    int min() {
        return minStack.top();
    }
};
```
