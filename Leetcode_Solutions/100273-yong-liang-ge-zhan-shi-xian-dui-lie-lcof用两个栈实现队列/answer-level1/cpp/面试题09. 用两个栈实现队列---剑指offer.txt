`剑指offer---P68-72`

1. 插入元素时，直接把它压入s1。删除元素，当s2不为空时，s2的栈顶元素是最先进入队列的元素，可以弹出。当s2为空时，把s1的元素逐个弹出并压入到s2中。

```
class CQueue {
public:
    stack<int>s1,s2;

    CQueue() {
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty() && s2.empty())return -1;
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int qHead=s2.top();
        s2.pop();
        return qHead;
    }
};
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```