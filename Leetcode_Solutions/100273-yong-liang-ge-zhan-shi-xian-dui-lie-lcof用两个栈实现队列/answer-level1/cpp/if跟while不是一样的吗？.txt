```
class CQueue {
public:
    CQueue() {

    }
    
    stack<int> s1;
    stack<int> s2;

    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty() && s2.empty())
            return -1;
        if(s2.empty()){
            **while(!s1.empty()**){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }
};

```
```
class CQueue {
public:
    CQueue() {

    }
    
    stack<int> s1;
    stack<int> s2;

    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty() && s2.empty())
            return -1;
        if(s2.empty()){
            **if(!s1.empty())**{  //这样写就会报错！
                s2.push(s1.top());
                s1.pop();
            }
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }
};

```
请大佬指点一下