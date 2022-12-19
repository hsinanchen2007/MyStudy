内部也使用栈，只是存储数据封装成pair<min, value>，所有操作可直接使用栈操作。


```c++
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if(x < min) {
            min = x;
        }

        minStack.push(make_pair(min, x));
    }
    
    void pop() {
        minStack.pop();
        if (minStack.empty()) {
            min = INT_MAX;
        } else {
            min = minStack.top().first;
        }
    }
    
    int top() {
        return minStack.top().second;
    }
    
    int getMin() {
        return minStack.top().first;
    }

private:
    int min = INT_MAX;
    stack<pair<int, int>> minStack;
};
```
