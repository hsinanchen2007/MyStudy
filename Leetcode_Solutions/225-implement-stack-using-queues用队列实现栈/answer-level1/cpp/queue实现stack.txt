### 解题思路
栈的操作：
    push(int x) : 插入数据x，调用queue的push可直接插入数据
    pop() ： 删除栈顶元素并返回，queue从队头弹出元素，再将元素插入队尾，直到队头为最后一个元素，即为栈顶。保存下来再调用queue的pop()删除。
    top() ： 返回栈顶元素，调用MyStack类的pop得到栈顶元素，再将元素插入到队尾，返回即可。
    empty() : 直接返回queue的empty

### 代码

```cpp
class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for(int i = 0; i < q.size() - 1; ++i){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        int res  = q.front();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res = pop();
        q.push(res);
        return res;
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