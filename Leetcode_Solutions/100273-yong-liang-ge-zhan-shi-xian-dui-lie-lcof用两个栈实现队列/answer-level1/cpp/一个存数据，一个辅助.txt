### 解题思路


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
        if (s2.size() == 0 && s1.size() == 0) {
            return -1;
        }
        if (s2.size() == 0) {
            while(s1.size() != 0) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int value = s2.top();
        s2.pop();
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