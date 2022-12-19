### 解题思路
没什么可写的...（刚开始capacity是100没过，从100变为10000就过了）

### 代码

```cpp
class MinStack {
public:
    int* stack;
    int* temp;
    int capacity = 10000;
    int count = 0;
    int tempCount = 0;
    /** initialize your data structure here. */
    MinStack() {
        stack = new int[capacity];
        temp = new int[capacity];
    }
    
    void push(int x) {
        stack[count++] = x;
        if (tempCount == 0)
            temp[tempCount++] = x;
        else
            {
                if (x <= temp[tempCount-1])
                    temp[tempCount++] = x;
                else
                    ;
            }
    }
    
    void pop() {
        if (stack[count-1] == temp[tempCount-1])
            tempCount--;
        count--;
    }
    
    int top() {
        return stack[count-1];
    }
    
    int getMin() {
        if (tempCount == 0)
            return 0;
        return temp[tempCount-1];
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