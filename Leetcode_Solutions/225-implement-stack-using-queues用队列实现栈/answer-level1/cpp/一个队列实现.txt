### 解题思路
每次push的时候将队列内的所有元素往后移，将push的x放在队首来模拟d栈
实现就是把队列中已有的元素依次再加入队列并弹出自己

### 代码

```cpp
class MyStack {
public:
    queue<int> list;
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        list.push(x);
        for(int i=0;i<list.size()-1;i++)
        {
            list.push(list.front());
            list.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t=top();
        list.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return list.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return list.empty();
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