### 解题思路
栈p为输入栈，栈q为输出栈，输出时，若栈q不为空，则返回q.top()，否则若栈p不为空，将栈p元素反转存入栈q，返回q.top()，若都为空，返回-1

### 代码

```cpp
class CQueue {
public:
    stack<int> p,q;
    CQueue() {

    }
    
    void appendTail(int value) {
        p.push(value);
    }
    
    int deleteHead() {
        if(p.empty()&&q.empty())
            return -1;
        else
            if(!p.empty()&&q.empty()){
                while(!p.empty()){
                    int t=p.top();
                    p.pop();
                    q.push(t);
                }
            }
        int t=q.top();
        q.pop();
        return t;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```