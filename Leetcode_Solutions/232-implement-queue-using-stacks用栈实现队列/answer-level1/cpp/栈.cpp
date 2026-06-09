执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.4 MB, 在所有 C++ 提交中击败了100.00%的用户
### 解题思路
//一个数据栈，一个辅助栈，一个队首位

### 代码

```cpp
class MyQueue {
public:
    stack<int> s;
    int head;
    /** Initialize your data structure here. */
    MyQueue() {
        head=0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s.empty())
            head=x;
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> temp;
        while(!s.empty())
        {
            temp.push(s.top());
            s.pop();
        }
        int rs=temp.top();
        temp.pop();
        if(!temp.empty())
            head=temp.top();
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
        
        return rs;
    }
    
    /** Get the front element. */
    int peek() {
        return head;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
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