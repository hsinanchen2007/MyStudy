一个栈存数值，一个同步保存当前最小值。
话说这个不超过2万次调用，emmm是我实现的这个意思么？>_<

```
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        time++;
        if(time > 20000) exit(0);
        s.push(x);
        int mini = (!m.empty() && x >= m.top())? m.top() : x;
        m.push(mini);
    }
    
    void pop() {
        time++;
        if(time > 20000) exit(0);
        s.pop();
        m.pop();
    }
    
    int top() {
        time++;
        if(time > 20000) exit(0);
        return s.top();
    }
    
    int min() {
        time++;
        if(time > 20000) exit(0);
        return m.top();
    }
private:
    stack<int> s;
    stack<int> m;
    int time = 0;
};


```
