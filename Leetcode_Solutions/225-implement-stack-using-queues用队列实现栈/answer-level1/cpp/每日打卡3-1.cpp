### 解题思路
考虑到两种数据结构的特点：
- 队列：先入先出
- 栈：后入先出
入栈可以不用模拟，主要在出栈的时候进行模拟，为了能够用先入先出模拟后入先出，在出栈时，可以将队列的前`n-1`个元素，取出重新入队。然后让队列头部的元素出队，这样后入的就(在队列尾)就可以先出。

### 代码

```cpp
class MyStack {
    queue<int> q;
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
        int size = q.size();
        for (auto i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        int size = q.size();
        for (auto i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.push(ans);
        q.pop();
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
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