### 解题思路
此处撰写解题思路
不知道算不算作弊，vector算基本的队列吗
### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    vector<int>q;
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        this->q.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int back=q[q.size()-1];
        q.pop_back();
        return back;
    }
    
    /** Get the top element. */
    int top() {
        return q[q.size()-1];;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.size()==0;
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