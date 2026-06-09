```
class MaxStack {
public:
    /** initialize your data structure here. */
    stack<int> data;
    stack<int> max_data;
    MaxStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if(max_data.empty() || x >= max_data.top())
            max_data.push(x);
    }
    
    int pop() {
        if(data.empty())
            return 0;
        int ret = data.top();
        data.pop();
        if(ret == max_data.top())
            max_data.pop();
        return ret;
    }
    
    int top() {
        if(data.empty())
            return 0;
        return data.top();
    }
    
    int peekMax() {
        if(max_data.empty())
            return 0;
        return max_data.top();
    }
    
    int popMax() {
        int ret = 0;
        stack<int> tmp;
        if(data.empty() || max_data.empty())
            return 0;
        while(data.top() < max_data.top())
        {
            tmp.push(data.top());
            data.pop();
        }
        ret = max_data.top();
        data.pop();
        max_data.pop(); 
        while(!tmp.empty())
        {
            push(tmp.top());
            tmp.pop();
        }
        return ret;
    }
};
```
