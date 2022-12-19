需要初始化两个长度为20000的数组，一个存放数据，一个存放最小值

代码
```
class MinStack {
public:
    int num[20000];
    int m[20000];
    int i = 0;
    int Min = 0x7FFFFFFF;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (i == 0)
        {
            m[i] = x;
            Min = x;
        }
        else
        {
        if (x < m[i - 1])
            Min = x;
        m[i] = Min;
        }
        num[i] = x;
        i++;
    }
    
    void pop() {
        i--;
        if (i != 0 && m[i] == Min)
            Min = m[i - 1];
    }
    
    int top() {
        return num[i - 1];
    }
    
    int min() {
        return m[i - 1];
    }
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
