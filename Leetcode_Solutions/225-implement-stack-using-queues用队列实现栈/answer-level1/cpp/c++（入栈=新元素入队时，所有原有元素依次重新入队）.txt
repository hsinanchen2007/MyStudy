### 解题思路
- 入栈=新元素入队时，所有原有元素依次重新入队
- 时间复杂度：
  - 入栈：o(n)
  - 出栈：o(1)

### 代码

```cpp
class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++) q.push(q.front()),q.pop();
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res=q.front();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
```