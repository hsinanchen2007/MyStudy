### 解题思路
此处撰写解题思路
stack加入元素的时候直接添加，删除元素的时候先把所有元素倒入辅助栈中 然后删除最后一个 再把辅助栈中元素倒回去。
加入元素 时间复杂度O(1) 空间复杂度O(1)
删除元素 时间复杂度O(n) 空间复杂度O(n)

### 代码

```cpp
#include <stack>

class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        StackData.push(value);
    }
    
    int deleteHead() {
        if(StackData.size()==0) return -1;

        while(!StackSpare.empty())
        {
            StackSpare.pop();
        }

        while(StackData.size()>1)
        {
            StackSpare.push( StackData.top() );
            StackData.pop();
        } 

        int ResultVaL = StackData.top();
        StackData.pop();

        while(StackSpare.size()>0)
        {
            StackData.push( StackSpare.top() );
            StackSpare.pop();
        } 

        return ResultVaL;
    }

private:
    stack<int> StackData;
    stack<int> StackSpare;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```