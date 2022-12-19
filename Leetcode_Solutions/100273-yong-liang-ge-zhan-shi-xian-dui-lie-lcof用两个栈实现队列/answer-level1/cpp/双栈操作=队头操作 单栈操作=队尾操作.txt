### 解题思路
此处撰写解题思路

### 代码

```cpp
//栈1->栈2->出栈 <-> 队列队头出队
//栈2->栈1->出栈 <-> 队列队尾出队
class CQueue {
public:
    stack<int> s1;
    stack<int> s2;

    CQueue() {

    }
    
    void appendTail(int value) {
    //将s2元素放到s1中
            while (!s2.empty()) {
                int val = s2.top();
                s2.pop();
                s1.push(val);
            }
        s1.push(value);//队尾插入整数
    }
    int deleteHead() {
        while(!s1.empty()) { //将s1元素放到s2后 进行队头出队
            int val = s1.top();
            s1.pop();
            s2.push(val);
        }
        if (s2.empty()) return -1;
        int val = s2.top();
        s2.pop();        
        return val;        
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

```