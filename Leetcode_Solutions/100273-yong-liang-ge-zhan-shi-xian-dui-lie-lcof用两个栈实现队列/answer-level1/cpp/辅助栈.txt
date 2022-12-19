### 解题思路
利用辅助栈实现。
栈是先入后出，堆是先入先出。
所以，两个栈操作下，就得到先入先出的堆了。

### 代码

```cpp
class CQueue {
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        main_stk.push(value);
    }
    //入栈出栈，再入栈出栈
    int deleteHead() {
        int res = 0;
        if(main_stk.empty() && help_stk.empty()) return -1;
        if(!help_stk.empty()){
            res = help_stk.top();
            help_stk.pop();
            return res;
        }
        else{
            while(!main_stk.empty()){
                help_stk.push(main_stk.top());
                main_stk.pop();
            }
            res = help_stk.top();
            help_stk.pop();
            return res;
        }
    }
private:
    stack<int> main_stk;
    stack<int> help_stk;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```