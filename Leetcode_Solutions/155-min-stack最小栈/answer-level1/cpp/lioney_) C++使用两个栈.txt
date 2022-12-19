`辅助栈m用来存放某个阶段内出现的最小元素，栈顶元素表示到当前为止出现的最小元素`
```
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(m.empty() || x <= m.top()) {
            m.push(x);
        }
    }
    
    void pop() {
        if(s.top() == m.top()) {
            m.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
private:
    stack<int> s, m;
};
```
