### 解题思路
    一共两个栈,一个stackdata用来存放所有的数据,一个stackmin栈用来存放栈的最小值.push的时候,如果这个x比stackmin这个栈的最小值(也就是stackmin.top())小,就压入stackmin,如果不小,就压入此时stackmin栈的最小值,这样可以保证,stackmin的top是stackdata的最小值.

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stackdata.push(x);
        if(stackmin.empty())
        {
            stackmin.push(x);
        }
        else if(x<stackmin.top())
        {
            stackmin.push(x);
        }
        else
        {
            stackmin.push(stackmin.top());
        }
        
    }
    
    void pop() {
        if(!stackdata.empty())
        {
            stackdata.pop();            
        }
        if(!stackmin.empty())
        {
            stackmin.pop();            
        }
    }
    int top() {
         if(stackdata.empty())
        {
            cout<<"error"<<endl;          
        }   
        return stackdata.top();  
    }
    
    int getMin() {
        if(stackmin.empty())
        {
            cout<<"error"<<endl;          
        }
        return stackmin.top(); 
    }

private:
    stack<int> stackdata;
    stack<int> stackmin;
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