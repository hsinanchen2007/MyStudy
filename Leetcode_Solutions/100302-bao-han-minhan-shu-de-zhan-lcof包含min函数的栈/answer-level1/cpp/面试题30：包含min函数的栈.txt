### 解题思路


### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        _data.push(x);
        if(_min.empty())
        {
            _min.push(x);
        }
        else{
            if(x>_min.top())
            {
                _min.push(_min.top());
            }
            else{
                _min.push(x);
            }
        }
    }
    
    void pop() {
        _data.pop();
        _min.pop();
    }
    
    int top() {
        return _data.top();
    }
    
    int min() {
        return _min.top();
    }
private:
    stack<int> _min;
    stack<int> _data;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```