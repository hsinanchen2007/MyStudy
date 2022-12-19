### 解题思路
用队列实现栈 C++ 单队列 入栈O(N) 出栈O(1)

维护队列使其队头对应栈的栈顶，队尾对应栈的栈底。则需要在每次在队列尾部加入元素之后将原本就有的`que.size() - 1`个元素从头取出放回尾部以使队头对应栈顶，队尾对应栈底。

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for (int i = 0; i + 1 < que.size(); i++) {
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = top();
        que.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }

private:
    queue<int> que;
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