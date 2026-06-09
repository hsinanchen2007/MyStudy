两个栈，队列添加元素时，将数据加入第一个栈，出队以及取队头元素时，判断第二个栈是否为空，不为空则返回栈顶元素，否则将第一个栈的数据倒进第二个栈

```
class MyQueue {
private:
    stack<int> first, second;
    void move () {
        while (!first.empty()) {
            second.emplace(first.top());
            first.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        first.emplace(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (second.empty()) move();
        int top = second.top();
        second.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if (second.empty()) move();
        return second.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return first.empty() && second.empty();
    }
};
```
