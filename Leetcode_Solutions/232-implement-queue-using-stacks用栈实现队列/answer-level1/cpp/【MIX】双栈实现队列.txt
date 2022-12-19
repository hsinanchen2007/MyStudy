### 解题思路
使用一个辅助stack, 完成尾部插入的操作

### 代码

```c++ []
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!st.empty()) {mst.push(st.top()); st.pop();}
        st.push(x);
        while(!mst.empty()) {st.push(mst.top()); mst.pop();}
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int e = st.top();
        st.pop();
        return e;
    }
    
    /** Get the front element. */
    int peek() {
        return st.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }

private:
    stack<int> st;
    stack<int> mst;

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
```java []
```
```python []
```