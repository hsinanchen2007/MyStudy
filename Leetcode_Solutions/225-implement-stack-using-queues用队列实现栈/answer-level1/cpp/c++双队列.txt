### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int>temp_list;
        temp_list.push(x);
        while(!data.empty())
        {
            temp_list.push(data.front()); //把队列中的数移到临时队列
            data.pop();
        }
        while(!temp_list.empty())
        {
            data.push(temp_list.front());
            temp_list.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x=data.front();
        data.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return data.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
    queue<int>data;
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