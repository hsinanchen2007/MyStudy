```
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    int imin;
    MinStack() {
        imin = INT_MAX;
    }
    
    void push(int x) {
        stack.push_back(x);
        if(x<imin)
            imin = x;
    }
    
    void pop() {
        int n = stack.back();
        stack.pop_back();
        if(n == imin)
        {
            imin=INT_MAX;
            for (int n:stack)
            {
                if(n<imin)
                    imin=n;
            }
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return imin;
    }
};

```
方法2
```
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    vector<int> min_stack;
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        if(min_stack.size() ==0 || min_stack.back()>=x)
            min_stack.push_back(x);
    }
    
    void pop() {
        int n = stack.back();
        stack.pop_back();
        if(n == min_stack.back())
        {
            min_stack.pop_back();
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min_stack.back();
    }
};

```
