### 解题思路
1. 看题目，我以为要自己写一个栈的实现，还在想push怎么可能o(1)，毕竟要分配内存。如果把按stack的push算o(1)的话，那我也无话可说了。
2. 具体处理有两种思路：如果要速度快，就额外存储下到index为止的最小值；如果要空间小，就在删除的值和min相等的时候重新算下min。

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    int* stack;
    int capacity;
    int index;
    int* stackMin;
    MinStack() : capacity(1), index(-1) {
        stack = new int[capacity];
        stackMin = new int[capacity];
    }
    ~MinStack() {
        delete[] stack;
        delete[] stackMin;
    }
    
    void push(int x) {
        if (index+1 >= capacity) {
            int* temp = new int[capacity*2];
            memcpy(temp, stack, (index+1)*sizeof(int));
            delete[] stack;
            stack = temp;
            capacity *= 2;

            temp = new int[capacity];
            memcpy(temp, stackMin, (index+1)*sizeof(int));
            delete[] stackMin;            
            stackMin = temp;
        }
    
        stack[++index] = x;
        stackMin[index] = x;
        if (index > 0) {
            stackMin[index] = stackMin[index] < stackMin[index - 1] ? stackMin[index] : stackMin[index - 1];
        }
    }
    
    void pop() {
        if (index != -1) {            
            index--;
        }
    }
    
    int top() {
        return stack[index];
    }
    
    int getMin() {
        return stackMin[index];
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