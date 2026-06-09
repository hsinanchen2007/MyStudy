### 解题思路
要特别注意的地方：只有当输出栈为空的时候，才可以一次性把输入栈倒到 输出栈，
输出站不为空时，先让输出栈出栈

### 代码

```cpp
class CQueue {
public:
    stack<int>sin;    //输入栈
    stack<int>sout; //输出栈 辅助出队起到中转功能
    
                                                                                 
    CQueue() {

    }
    
    void appendTail(int value) {
        sin.push(value);   //入对的时候只管存进去
    }
    
    int deleteHead() {
        if (sin.empty() && sout.empty()) {
            return -1;
        }
        if (sout.empty()) {//输出栈为空时就可以把输入栈的倒进来
            while (!sin.empty()) {
                int v = sin.top(); 
                sout.push(v);
                sin.pop();
            }
        }   
        //输出栈不为空时要特殊考虑
            int value = sout.top(); 
            sout.pop(); //先把输出栈清空
            return value;
        }
};


/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```