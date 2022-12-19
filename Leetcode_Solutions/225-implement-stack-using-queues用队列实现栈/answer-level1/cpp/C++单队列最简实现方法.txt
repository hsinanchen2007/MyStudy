### 解题思路
在pop()的时候让队列前面的移动到队列最后，然后把队列原本最后的移除掉即可，其他的操作相同

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int len = q.size();
        int tem = 0;
        for(int i =1;i<len;i++)
        {
            tem = q.front();
            q.pop();
            q.push(tem);
        }
        tem = q.front();
        q.pop();
        return tem;
    }
    
    /** Get the top element. */
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```