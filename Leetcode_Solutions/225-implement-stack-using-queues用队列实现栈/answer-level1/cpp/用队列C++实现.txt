### 解题思路
创建临时队列，利用临时队列调换元素顺序，和用栈实现队列思想差不多，比较简单。

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> tmp;
        tmp.push(x);
        while(!arr.empty())
        {
            tmp.push(arr.front());
            arr.pop();
        }
        arr = tmp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = arr.front();
        arr.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res = arr.front();
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return arr.empty();
    }
private:
    queue<int> arr;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```