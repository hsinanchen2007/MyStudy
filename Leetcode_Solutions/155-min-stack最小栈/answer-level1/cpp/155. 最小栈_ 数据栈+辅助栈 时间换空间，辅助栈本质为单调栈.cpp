### 解题思路
此处撰写解题思路

### 代码

```cpp
//最小栈；
//时间换空间
//数据栈 + 辅助栈 予以实现
//辅助栈中的元素代表：当前层及以下中的最小元素
#include <stack>

class MinStack {
private:
    stack<int> dataStk, subStk;

public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        dataStk.push(x);
        if(subStk.empty()){
            subStk.push(x);
        }
        else{
            int topV = subStk.top();
            int tmp = (x < topV) ? x : topV;
            subStk.push(tmp);
        }
    }
    
    void pop() {
        dataStk.pop();
        subStk.pop();
    }
    
    int top() {
        return dataStk.top();
    }
    
    int getMin() {
        return subStk.top();
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