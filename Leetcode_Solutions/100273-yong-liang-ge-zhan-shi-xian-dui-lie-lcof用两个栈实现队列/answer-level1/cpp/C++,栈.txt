### 更新：
发现每次不用把s2又全部放入s1；当s2为空时再从s1往s2转换即可

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
        if(s1.empty()&&s2.empty()) return -1;
        if(s2.empty()){
            while(!s1.empty()){
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
        }
        int res=s2.top();
        s2.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```




### 原答案
每次push到s1里，为了保持顺序，先把s2的放回来

delete的时候从s1出栈，在push到s2里然后从s2出

### 代码

```cpp
class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {
    
    }
    
    void appendTail(int value) {
        while(!s2.empty()){
            int temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        s1.push(value); 
    }
    
    int deleteHead() {
        if(s1.empty()&&s2.empty()) return -1;
        while(!s1.empty()){
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        int res=s2.top();
        s2.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```

