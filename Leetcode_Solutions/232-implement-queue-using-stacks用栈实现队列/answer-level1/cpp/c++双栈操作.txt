### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int>stack_temp;
        while(!data.empty())
        {
            stack_temp.push(data.top());  //把data里面的数据全部倒到临时栈里面
            data.pop();
        }
        stack_temp.push(x);
        while(!stack_temp.empty())
        {
            data.push(stack_temp.top());
            stack_temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x=data.top();
        data.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return data.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
    stack<int>data; //这是我们的队列
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```