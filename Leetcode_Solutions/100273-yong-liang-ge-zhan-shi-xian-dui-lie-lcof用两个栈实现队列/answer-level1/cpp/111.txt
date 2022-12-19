### 解题思路
此处撰写解题思路

### 代码

```cpp
class CQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {
        stack<int> s1;
        stack<int> s2;
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        int del=-1;
        if(s2.size()!=0){
            del=s2.top();
            s2.pop();
        }
        else{
            while(s1.size()>0){
                int e=s1.top();
                s1.pop();
                s2.push(e);
            }
            if(s2.size()!=0){
                del=s2.top();
                s2.pop();
            }
        }
        return del;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```