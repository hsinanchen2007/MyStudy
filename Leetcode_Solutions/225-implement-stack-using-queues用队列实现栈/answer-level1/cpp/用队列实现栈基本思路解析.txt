### 解题思路
本题的核心在于理解队列的基本操作,队列的基本操作如下：
q.empty()               如果队列为空返回true，否则返回false
q.size()                返回队列中元素的个数
q.pop()                 删除队列首元素但不返回其值
q.front()               返回队首元素的值，但不删除该元素
q.push()                在队尾压入新元素
q.back()                返回队列尾元素的值，但不删除该元素
可以把栈顶当作是队列的尾部.
栈的push()操作即 返回队列的尾部的值并删除该元素；
栈的pop()操作即 返回队列的尾部的值删除该元素；
栈的top()操作即 返回队列的尾部值；
栈的empty()操作即 判断队列是否为空。

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
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for(int i=0;i<q.size()-1;i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int val=q.front();
        q.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
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