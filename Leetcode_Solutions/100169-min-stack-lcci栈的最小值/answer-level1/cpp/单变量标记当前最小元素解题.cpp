### 解题思路
![图片.png](https://pic.leetcode-cn.com/2a4a15ac165621e27effcac518f64330df78916bfdc1b03847fd5752000a5495-%E5%9B%BE%E7%89%87.png)

利用一个_min变量标记当前的最小栈内元素。
压栈时，如果最小元素发生变更，就把当前最小元素也进行压栈，标记这一次的最小元素变更情况。
出栈时，如果遇到当前最小值与栈顶元素相同的情况，就连着这个元素一起弹出，并将当前最小值更新为这个元素的下一个元素。

理论上这个方式比双栈更省空间。

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> _stack;
    int _min = INT_MAX;
    MinStack() {
        
    }
    
    void push(int x) {
        if(_min >= x){
            if(!_stack.empty()){
                _stack.push(_min);
            }
            _min = x;
        }
        _stack.push(x);
    }
    
    void pop() {
        if(_stack.empty())
            return;
        if(_stack.size() == 1)
            _min = INT_MAX;
        else if(_min == _stack.top()){//下一个元素是下一个最小值
            _stack.pop();
            _min = _stack.top();
        }
        _stack.pop();
    }
    
    int top() {
        return _stack.top();
    }
    
    int getMin() {
        return _min;
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