### 解题思路
此处撰写解题思路
保持栈的顶部为队列的队头，栈的底部为队列的队尾，定义两个栈，一个用于设计为队列，一个用于push新元素时存取已有元素
### 代码

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        int n = vecStack.size();
        for(int i = 0;i < n;i++){
            tmpStack.push(vecStack.top());
            vecStack.pop();
        }
        vecStack.push(x);
        for(int i = 0;i < n;i++){
            vecStack.push(tmpStack.top());
            tmpStack.pop();
        }

    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int Val;
        Val = vecStack.top();
        vecStack.pop();
        return Val;
    }
    
    /** Get the front element. */
    int peek() {
        return vecStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return vecStack.empty();
    }
private:
    stack<int> vecStack,tmpStack;
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