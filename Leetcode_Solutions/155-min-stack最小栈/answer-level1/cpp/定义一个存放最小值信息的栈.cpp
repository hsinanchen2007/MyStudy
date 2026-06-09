### 解题思路
每次push时，检查是否小于当前最小值（注意检查是否存有最小值，如果还没有存在，则插入为最小值），如果小于最小值，则插入为最小值。每次pop时，检查当前位置是否为最小值的位置，如果时，则从最小值中pop()出来。

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        mydata.push(x);
        DataPos newdata = {static_cast<int>(mydata.size()), x};
        if (mindata.empty()) {
            mindata.push(newdata);
        } else if (x < getMin()) {
            mindata.push(newdata);
        }
    }
    
    void pop() {
        if (static_cast<int>(mydata.size()) == mindata.top().pos) {
            mindata.pop();
        }
        mydata.pop();
    }
    
    int top() {
        return mydata.top();
    }
    
    int getMin() {
        return mindata.top().data;
    }

private:
    struct DataPos {
        int pos = 0;
        int data = 0;
    };
    stack<int> mydata;
    stack<DataPos> mindata;
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