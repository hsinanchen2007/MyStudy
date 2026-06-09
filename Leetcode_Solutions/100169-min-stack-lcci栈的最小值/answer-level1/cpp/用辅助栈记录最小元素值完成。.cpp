### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
    stack<int> s;
    stack<int> record;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (record.empty())
        {
            record.push(x);
        }
        else 
        {
            if (x <= record.top())
            {
                record.push(x);
            }
        }
    }
    
    void pop() {
        if (s.empty())
        {
            std::cerr << "empty stack!" << std::endl;
            std::exit(1);
        }
        else
        {
            int temp = s.top();
            s.pop();
            if (temp == record.top())
            {
                record.pop();
            }
        }
    }
    
    int top() {
        if (s.empty())
        {
            std::cerr << "empty stack!" << std::endl;
            std::exit(1);
        }
        else
        {
            return s.top();
        }
        
    }
    
    int getMin() {
        if (record.empty())
        {
            std::cerr << "empty stack!" << std::endl;
            std::exit(1);
        }
        else
        {
            return record.top();
        }
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
```