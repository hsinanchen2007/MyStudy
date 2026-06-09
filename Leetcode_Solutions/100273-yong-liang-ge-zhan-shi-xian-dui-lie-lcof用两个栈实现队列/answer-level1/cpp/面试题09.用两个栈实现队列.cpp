### 解题思路
核心要点：两个stack类型成员变量，入队=s1.push，出队=if s2非空->s2.pop else s1全部弹出到s2 再s2.pop
执行用时 :464 ms, 在所有 C++ 提交中击败了49.37%的用户
内存消耗 :105.2 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class CQueue {
    stack<int>s1;
    stack<int>s2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()){
            if(s1.empty()){
                return -1;
            }
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }               
            }
        }
        int head=s2.top();
        s2.pop();
        return head;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```