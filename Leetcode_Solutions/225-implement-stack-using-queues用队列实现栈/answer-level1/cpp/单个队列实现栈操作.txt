### 解题思路
    纯数据结构基础，抓住栈的操作以及队列操作的特点，然后稍加注意
    注意pop操作和push操作
### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    queue<int> q;
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = q.front();
        q.pop();
        return tmp;
    }
    void push(int x) {
        int size = q.size();
        q.push(x);
        int tmp;
        for(int i = 0; i < size; i++){
            q.push(q.front());
            q.pop();
        }
    }

    /** Get the top element. */
    int top() {
        int tmp = q.front();
        return tmp;
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