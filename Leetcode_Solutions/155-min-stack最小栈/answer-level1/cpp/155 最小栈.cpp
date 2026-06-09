### 解题思路
底层用deque实现，不需要来回拷贝，但是相比于stack，没快多少

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    deque<int> _s;
    int _min;
    void push(int x) {
        if (_s.empty() || x < _min) _min = x;
        _s.push_back(x);
    }
    
    void pop() {
        if (_s.empty()) return;
        int m = _s.back();
        _s.pop_back();
        if (!_s.empty() && m == _min) {
            _min = _s.back();
            for (auto i : _s) {
                _min = min(_min, i);
            }
        }

    }
    
    int top() {
        return _s.back();
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