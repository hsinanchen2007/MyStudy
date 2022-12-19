这个题目字节跳动喜欢考，之前就被问到过，一定要知道。
双栈法：
push的时候，push到一个栈中，pop的时候如果另一个栈为空，就把第一个栈的内容全部push进来，然后输出栈顶，如果不为空，就直接输出另一个栈的栈顶。
```
class CQueue {
public:
    stack<int> s1,s2;
    CQueue() {
    }
    void appendTail(int value) {
        s1.push(value);
    }
    int deleteHead() {
        if(s2.empty()&&s1.empty())
            return -1;
        if(s2.empty())
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        int val = s2.top();
        s2.pop();
        return val;
    }
};
```