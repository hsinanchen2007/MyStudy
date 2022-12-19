### 解题思路
基本思路：一个栈s1负责入队，另一个栈s2负责出队。在要删除队尾时，将s1的元素压入s2，此时s2的顺序与队列顺序一致，要删的队尾即s2栈顶元素。
技巧：执行一次删除后，s2中存放了原来摆好的队列，只要s2没空，就可以继续退栈顶，不用挪s1中的元素。如果s2空了，判断s1是否还有，有的话执行基本思路，把s1的元素压到s2。只有s1和s2都空了，才return -1 。

### 代码

```cpp
class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (s2.empty())
        {
            if (s1.empty())
                return -1;
            else
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }

            }
        }
        int res;
        res = s2.top();
        s2.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```