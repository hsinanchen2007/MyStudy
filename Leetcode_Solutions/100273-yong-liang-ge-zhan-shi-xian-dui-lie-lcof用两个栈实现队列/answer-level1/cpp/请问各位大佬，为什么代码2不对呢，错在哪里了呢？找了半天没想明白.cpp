### 解题思路
请问各位大佬，为什么代码2不对呢，错在哪里了呢？找了半天没想明白

### 代码
代码1
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
        if(s1.empty()&&s2.empty())
           return -1;
        if(s2.empty()&&!s1.empty())
        {
           while(!s1.empty())
           {
               s2.push(s1.top());
               s1.pop();
           }
        }
        int res=0;
        res=s2.top();
        s2.pop();
         return res;
    }
};
代码2
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
        for(int i=0;i<s1.size();i++)
        {
            s2.push(s1.top());
            s1.pop();
        }
        if(s2.empty())
          return -1;
        int res=0;
        res=s2.top();
        s2.pop();
         return res;
    }
};
```