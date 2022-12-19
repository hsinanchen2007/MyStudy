### 解题思路
此处撰写解题思路
堆栈只能后进先出，如果要模拟队列的先进先出，就需要一个零时堆栈来缓存上一次的数据，从而模拟队列的尾部插入
### 代码

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        while(mStack.size()){
            temp.push(mStack.top());
            mStack.pop();
        }

        mStack.push(x);
        while(temp.size()){
            mStack.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = mStack.top();
        mStack.pop();

        return ret;
    }
    
    /** Get the front element. */
    int peek() {
       return mStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return mStack.size() ? false : true;
    }
private:
    stack<int> mStack;
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