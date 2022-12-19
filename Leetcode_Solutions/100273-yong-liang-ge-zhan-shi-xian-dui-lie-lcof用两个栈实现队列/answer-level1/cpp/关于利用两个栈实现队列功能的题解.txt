### 解题思路
利用两个栈实现队列的普通功能，当入队时，只需要普通的进行push栈操作便可。需要删除队首元素时，需要先将栈1中的元素全部出栈。然后将出栈的元素全部入栈到stack2，然后将栈顶元素出栈。除了栈顶元素后，全部压入栈1；然后返回原来的栈2的栈顶元素即可

### 代码

```cpp
class CQueue {
public:
stack<int>stack1;
stack<int>stack2;
    CQueue() {
        stack<int>stack1;
        stack<int>stack2;

    }
    
    void appendTail(int value) {
        stack1.push(value);

    }
    
    int deleteHead() {
        if(stack1.size()==0)
        {
            return -1;
        }
        while(stack1.size()!=0){
        int temp=stack1.top();
        stack1.pop();
        stack2.push(temp);
        }
        int res=stack2.top();
        stack2.pop();
        while(stack2.size()!=0)
        {
            int temp2=stack2.top();
            stack2.pop();
            stack1.push(temp2);
        }
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