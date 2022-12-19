### 解题思路
栈顶————队首
栈底————队尾
push：由于插入元素在是在栈尾，因此push进去之后，再循环将之前的元素挪到栈尾来，保证push的元素在队首，即栈顶。
pop：返回的元素为栈顶，即队首元素，front()，再删除栈顶元素pop()
top：返回的元素为栈顶，即队首元素，front()
empty：队列的empty()方法

### 代码

```cpp
class MyStack {
public:
    queue<int> que;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for (int i = 0; i < que.size() - 1; i++) {
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int a = que.front();
        que.pop();
        return a;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
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