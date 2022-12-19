### 解题思路
此处撰写解题思路

### 代码

```cpp
class CQueue {
private:
    stack<int> a;
    stack<int> b;
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        b.push(value);
    }
    
    int deleteHead() {
        if(a.empty() && b.empty()) return -1;

        if(a.empty()){
            while(!b.empty()){
                a.push(b.top());
                b.pop();
            }
        }

        int ans = a.top();
        a.pop();
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```