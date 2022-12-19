### 解题思路
只需要在push时使队列的顺序调整为栈的存储顺序即可。
在pop以及取top值时调用队列的原函数。

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for(int i = 0; i < q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        topV = q.front();
        q.pop();
        return topV ;
    }
    
    /** Get the top element. */
    int top() {
        topV = q.front();
        return topV;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
    private:
    queue<int> q;
    
    int topV;
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