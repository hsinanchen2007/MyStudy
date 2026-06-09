### 解题思路
此处撰写解题思路
使用Instack作为输入数据的stack OutStack作为输出数据的stack 不用每次删除都倒入倒出数据 只需在OutStack为空的时候把Instack数据一次性倒入即可
不存在倒出的现象。而且OutStack不为空的时候不需要倒入数据 一直删除到OutStack为空为止。

### 代码

```cpp
class CQueue {
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        InStack.push(value);
    }
    
    int deleteHead() {
        if(InStack.empty() & OutStack.empty())
        {
            return -1;
        }

        TransformStack();

        int TmpValue = OutStack.top();
        OutStack.pop();
        return TmpValue;
    }

    void TransformStack()
    {
        if(OutStack.empty())
        {
            while(!InStack.empty())
            {
                OutStack.push(InStack.top());
                InStack.pop();
            }
        }
    }

    stack<int> InStack;
    stack<int> OutStack;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```