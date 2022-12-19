### 解题思路
使用两个队列q1,q2，一个进行push/empty操作，另一个辅助进行top/pop操作,即q1存储数据，由于队列是先进先出因此需要另外一个队列进行帮助把最后一个数据之前的数据移动，然后把最后一个数据也就是需要后进先出的数据进行top/pop操作。

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        return;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty())return -1;
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int out=q1.front();
        q1.pop();
         while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return out;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty())return -1;
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int out= q1.front();
        q2.push(out);
        q1.pop();
         while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return out;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;

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