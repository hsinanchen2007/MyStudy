class MinStack {
public:
//解答本问题的关键在于最小元素的返回，采取空间换时间的方式，加一个辅助栈s2来存放栈的最小元素。
//只有插入的元素比s2的小才入栈，出栈的时候只有和s2的一样才出栈。
    /** initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    MinStack() {

    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() || x<=s2.top())
            s2.push(x);
    }
    
    void pop() {
        if(s1.top()==s2.top())
        s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */