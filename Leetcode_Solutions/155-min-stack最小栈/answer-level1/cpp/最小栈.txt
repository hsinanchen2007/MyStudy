参考1718ZhangYQ的题解“Python[数据栈+辅助栈]”，设计了主栈和辅助栈，辅助栈中存放的是每个位置所对应的栈内的最小值，因此pop()和getMin()可以直接得到，当push()的时候，判断msta.top()和元素x的关系，进而决定该加入哪个元素，实现如下：
```
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(msta.empty()){
            msta.push(x);
        }else{
            if(msta.top()<=x) msta.push(msta.top());
            else msta.push(x);
        }
        sta.push(x);
    }
    
    void pop() {
        if(sta.empty()) return;
        msta.pop();
        sta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return msta.top();
    }
private:
    stack<int> sta;
    stack<int> msta;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```