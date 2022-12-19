### 解题思路
这道题思路就是使用两个栈，一个栈添加元素，对应栈的push，一个栈删除元素，对应栈的pop。添加元素直接将数据push到栈1中即可。删除元素需要将栈1中的元素push到栈2中，达到数据逆序的目的，再取栈顶的元素并pop即可。但这里需要注意的是，如果栈2不空时，直接pop栈顶元素，不能将栈1新添加元素再push进来，即删除操作过程，每次必须要等到栈2空了才能从栈1push元素到栈2中。
### 代码

```cpp
class CQueue {
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        if(stk1.empty() && stk2.empty()){
            return -1;
        }

        if(stk2.empty()){
            while (!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }

        int d = stk2.top();
        stk2.pop();

        return d;
    }

private:
    std::stack<int> stk1;
    std::stack<int> stk2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```