### 解题思路
1.stack1只用于入队，Stack2只用于出队。
2.入栈时直接放入stack1,出栈时若stack2不空直接删其栈顶，若stack2为空，把stack1中元素倒进stack2,然后删除其栈顶，若stack1也空则返回-1.

### 代码

```cpp
class CQueue {
public:
    stack<int>stackIn;
    stack<int>stackOut;
    CQueue() {

    }

    void appendTail(int value) {
         stackIn.push(value);
    }

    int deleteHead() {
        if(!stackOut.empty()) {int value=stackOut.top();stackOut.pop();return value;}
        else if(!stackIn.empty()){
            while(!stackIn.empty()){
                int value=stackIn.top();
                stackIn.pop();
                stackOut.push(value);
            }
            int value=stackOut.top();
            stackOut.pop();
            return value;
        }
        else return -1;
    }
};
```