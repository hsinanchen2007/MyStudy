用了一个vector里面放了一个pair对去做的，这个pair值存了当前插入值之前对应的最小值，所以即使你出栈了数值，剩下的栈顶元素的pair的第二个数值仍然对应当前栈的最小值

class MinStack {
    vector<pair<int,int>> stk;
public:
    /** initialize your data structure here. */    
    
    MinStack() {        
        stk.push_back(make_pair<int,int>(0,INT_MAX));
    }
    
    void push(int x) {
        stk.push_back(make_pair(x,min(x,stk.back().second)));
    }
    
    void pop() {
        if(stk.size()>1)
            stk.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }    
};