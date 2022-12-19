### 解题思路
此处撰写解题思路
通过两个队列实现pop()和top()函数，
1.pop() 
将q队列的值依次压入p队列，q队列最后一个值不压入，将其返回并删除；再将p队列的值重新压入q队列
2.top()
跟pop()实现类似，但是不删除q最后一个值,最后还将其压入q队列

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
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
        int size = q.size();
        queue<int> p;
        for(int i=0;i<size-1;i++){
            p.push(q.front());
            q.pop();
        }
            
        int temp = q.front();
        q.pop();
        for(int i=0;i<size-1;i++){
            q.push(p.front());
            p.pop();
        }
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        int size = q.size();
        queue<int> p;
        for(int i=0;i<size-1;i++){
            p.push(q.front());
            q.pop();
        }
            
        int temp = q.front();
        q.pop();
        
        for(int i=0;i<size-1;i++){
            q.push(p.front());
            p.pop();
        }
        q.push(temp);
        return temp;
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