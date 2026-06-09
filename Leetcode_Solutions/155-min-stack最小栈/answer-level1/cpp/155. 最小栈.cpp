### 解题思路
* 用两个栈维护数据：
* 一个栈放原始数据；
* 另一个栈存最小值；
* 栈的性质：最小值min压入，在之后压入的比min大的数不影响返回最小值（先于min被推出）；但是小于等于min的数会影响，所以要用另一个栈记录它（们）。
* 类同[队列的最大值](https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-ii-dui-lie-de-zui-da-zhi-guan-fang-/)

### 代码

```cpp
class MinStack {
    stack<int> stk;
    stack<int> minstk;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        stk.push(x);
        if(minstk.empty()) {
            minstk.push(x);
        }
        else if(x <= minstk.top()) {
            minstk.push(x);
        }
    }
    
    void pop() {
        int top = stk.top();
        stk.pop();
        if(top == minstk.top()) {
            minstk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
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
![1.png](https://pic.leetcode-cn.com/98b1f2b3d785d27cb389f7becedf2a0351780fede2ba7945773e624c5ed7f8ef-1.png)
