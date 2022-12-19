### 解题思路
这个思路比较巧。当有更小的值的时候，先把以前的最小值压入，然后再压入新的最小值。
弹出的时候，假如弹出的值和当期的最小值是一样的，说明下一个值是之前的最小值，再弹出一次取到这个值。

### 代码

```cpp
class MinStack {
private:
    stack<int> minSt;
    int minValue = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (x <= minValue) {
            //先压入当期最小值，然后更新最下值，再压入当前值
            minSt.push(minValue);
            minValue = x;
        }
        minSt.push(x);
    }

    void pop() {
        int t = minSt.top();
        minSt.pop();
        if (t == minValue) {
            //如果弹出来的是最小值，那么上一次的最小值就在下面，继续弹出来
            minValue = minSt.top();
            minSt.pop();
        }
    }

    int top() {
        return minSt.top();
    }

    int min() {
        return minValue;
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