```
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        temp.push_back(x);
    }
    
    void pop() {
        if(!temp.empty())
            //cout<<"error"<<endl;
            temp.pop_back();
    }
    
    int top() {
        if(!temp.empty())
            cout<<"error"<<endl;
        return temp.back();
    }
    
    int getMin() {
        if(temp.empty())
            cout<<"error"<<endl;
        return *min_element(temp.begin(),temp.end());
    }
    private:
        vector<int>temp;
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
