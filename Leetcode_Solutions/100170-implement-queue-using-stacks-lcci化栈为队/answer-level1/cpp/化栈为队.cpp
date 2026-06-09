### 解题思路

保证数据栈中的弹出顺序同队列一样，每次有新数据，先将数据栈其压入缓冲栈，之后将数据压入缓冲栈，最后扔到数据栈保证顺序。

### 代码

```cpp

#include<stack>
using namespace std;
class MyQueue {
public:
    stack<int> data_;
    stack<int> temp_;

    //321->  new:5 1.123->new temp->data_
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!data_.empty())
        {
            temp_.push(data_.top());
            data_.pop();
        }
        temp_.push(x);
        while(!temp_.empty())
        {
            data_.push(temp_.top());
            temp_.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top=data_.top();
        data_.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return data_.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data_.empty();
    }
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