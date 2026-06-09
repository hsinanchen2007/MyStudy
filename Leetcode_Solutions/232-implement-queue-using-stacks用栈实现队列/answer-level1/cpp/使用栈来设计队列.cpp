使用栈设计队列：
1.新建一个临时栈，把数据栈中的数据放在临时栈中。
2.把新数据压入临时栈中。
3.把临时栈中的数据压入数据栈中。
```
/*

分析，用栈实现队列
栈：先进后出
队列：先进先出
增加一个临时栈即可

*/
#include<stack>
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> _newdata;
        while(!_data.empty())
        {
            _newdata.push(_data.top());
            _data.pop();    /*_data中元素出栈*/
        }
        _newdata.push(x);
        while(!_newdata.empty())
        {
            _data.push(_newdata.top());
            _newdata.pop();            
        }
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x=_data.top();
        _data.pop();
        return x;
    }
    /** Get the front element. */
    int peek() {
        return _data.top();
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        return _data.empty();
    }
    private:
    stack<int> _data;
    
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
