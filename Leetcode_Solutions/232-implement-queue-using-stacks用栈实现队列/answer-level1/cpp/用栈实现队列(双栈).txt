### 解题思路
使用多一个栈buf作为缓冲，push操作直接加入buf中，
当主栈st为空时，buf栈直接倒入st中
使用peek或pop时，才确认st是否为空

### 代码

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        buf.push(x);
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(st.empty()){
            while(!buf.empty()){
                st.push(buf.top());
                buf.pop();
            }
        }
        int val = st.top();
        st.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if(st.empty()){
            while(!buf.empty()){
                st.push(buf.top());
                buf.pop();
            }
        }
        return st.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty() && buf.empty();
    }
    
    private:
    stack<int> st;
    stack<int> buf;
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