### 解题思路
模拟题

### 代码

```cpp
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(value);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int deleteHead() {
        if(s1.empty()) return -1;
        int res=s1.top();
        s1.pop();
        return res;
    }
private:
    stack<int> s1;
    stack<int> s2;
};
```