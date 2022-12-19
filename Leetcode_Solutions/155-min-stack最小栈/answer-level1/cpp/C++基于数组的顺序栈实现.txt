### 解题思路
基于数组实现顺序栈。
采用辅助栈存储最小值，实现O(1)时间复杂度内返回最小值。

### 代码

```cpp
class MinStack {
private:
    /** initialize your data structure here. */
    int* arr; // 数组 
    int* arr_min; // 定义辅助栈的数组
    int count; // 栈中元素个数 
    int count_min; // 辅助栈中元素个数

public:
    MinStack() {
        arr = new int[1000];
        arr_min = new int[1000];
        count = 0;
        count_min = 0;
    }
    
    void push(int x) {
        // 数组空间不够了，直接返回false，入栈失败。 
        if (count == 1000 || count_min == 1000) return;
        // 将x放到下标为count的位置，并且count加一 
        arr[count] = x;
        ++count;
        if (count_min == 0 || x <= arr_min[count_min-1]) {
            arr_min[count_min] = x;
            ++count_min;
        }
        return;
    }
    
    void pop() {
        // 栈为空，则直接返回NULL
        if (count == 0) return;
        // 返回下标为count-1的数组元素，并且栈中元素个数count减一 
        int tmp = arr[count-1];
        //cout << tmp << endl;
        --count;
        if (tmp == arr_min[count_min-1]) {
            --count_min;
        }
        return;
    }
    
    int top() {
        // 栈为空，则直接返回NULL
        if (count == 0) return NULL;
        // 返回下标为count-1的数组元素，并且栈中元素个数count不变
        return arr[count-1];
    }
    
    int getMin() {
        if (count_min == 0) return NULL;
        return arr_min[count_min-1];
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