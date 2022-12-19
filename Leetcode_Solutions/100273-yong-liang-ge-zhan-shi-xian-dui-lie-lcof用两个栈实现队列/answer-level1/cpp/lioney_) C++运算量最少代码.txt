```
class CQueue {
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    void reverseStack() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int deleteHead() {
        if(s1.empty() && s2.empty()) return -1;
        if(s2.empty()) {
            reverseStack();
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
private:
    stack<int> s1, s2;
};
```
