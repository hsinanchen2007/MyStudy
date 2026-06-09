### 解题思路
关键在于维护最小值，
其关键在于原有最小值被pop()后，如何更新，这里遍历stack就显得很困难
![image.png](https://pic.leetcode-cn.com/d4acfcc8c747f4ce6439f9cf59e3b3e50e4065364c0322be17567a50efeeecc9-image.png)

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    stack<int> _s;
    int _min;
    void push(int x) {
        if (_s.empty() || x < _min) _min = x;
        _s.push(x);
    }
    
    void pop() {
        if (_s.empty()) return;
        int m = _s.top();
        _s.pop();
        if (!_s.empty() && m == _min) {
            _min = _s.top();
            stack<int> tmp;
            while (!_s.empty()) {
                _min = min(_min, _s.top());
                tmp.push(_s.top());
                _s.pop();
            }
            while (!tmp.empty()) {
                _s.push(tmp.top());
                tmp.pop();
            }
        }

    }
    
    int top() {
        return _s.top();
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