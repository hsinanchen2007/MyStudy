### 解题思路
思路是每次插入完以后 强行将队列的排序逆转过来，每次插入的时候前面的元素均为逆转，那么只需要把前面的元素依次弹出再插入到队尾就能实现。
时间复杂度为O(n)

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int sz = q.size();
        q.push(x);
        for(int i=1;i<=sz;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int re = q.front();
        q.pop();
        return re;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
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