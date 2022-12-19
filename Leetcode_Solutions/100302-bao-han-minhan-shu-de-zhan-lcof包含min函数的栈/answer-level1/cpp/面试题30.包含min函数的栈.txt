### 解题思路
核心思路：借助辅助栈存放主栈的非增序列，保证辅助栈顶始终为主栈的最小值
执行用时 :48 ms, 在所有 C++ 提交中击败了12.71%的用户
内存消耗 :15.1 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class MinStack {
    stack<int>s1;
    stack<int>s2;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty()||x<=s2.top()){
            s2.push(x);
        }
    }
    
    void pop() {
        if(s1.empty())return;
        if(s1.top()==s2.top()){
            s1.pop();
            s2.pop();
        }
        else s1.pop();

    }
    
    int top() {
        return s1.top();
    }
    
    int min() {
        if(s2.empty())return 0;
        else return s2.top();
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