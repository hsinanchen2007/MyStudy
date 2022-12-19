### 解题思路
使用C++标准模板库queue模板类实现。

q.push(x)：将x插入到队列末端。
q.pop()：弹出队列的第一个元素（不会返回被弹出元素的值）。
q.front()：返回队首元素，即最早被压入队列的元素。
q.empty()：判断队列是否为空，当队列空时，返回true。

插入元素x定义了一个临时队列temp，然后将x插入到空的temp队列中，此时x是队首元素，即栈顶元素，然后将队列q（栈）中的所有元素依次取出并插入到temp队列的末端，此时得到的temp队列即将x入栈的得到的队列，然后再用同样的方法将temp队列的元素依次弹出并插入回队列q（栈）。

弹出栈顶元素即弹出队首元素，但需要返回弹出的队首元素值，而队列的pop()函数不会返回队首元素值，所以需要先定义一个临时int变量temp通过front()函数获取队首元素值，然后再弹出队首元素（即出栈），最后返回temp。

### 代码

```cpp
class MyStack {
public:

    queue<int> q;

    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> temp;
        temp.push(x);
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
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