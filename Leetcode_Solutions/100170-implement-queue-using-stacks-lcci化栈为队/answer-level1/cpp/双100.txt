### 解题思路
第一个栈保存正常push，另一个保存逆序栈，也就是队列顺序。第二个优先于第一个栈

### 代码

```cpp

class MyQueue {
public:
    stack<int> que;
    stack<int> temp;
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        que.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!temp.empty()){
            int value = temp.top();
            temp.pop();
            return value;
        }else{
            while(!que.empty()){
                temp.push(que.top());
                que.pop();
            }
            int value = temp.top();
            temp.pop();
            return value;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if(!temp.empty()){
            return temp.top();
        }else{
            while(!que.empty()){
                temp.push(que.top());
                que.pop();
            }
            return temp.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return que.empty() && temp.empty();
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