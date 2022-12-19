### 解题思路
有一定技巧，需要多一个栈，一个常数做不到

### 代码

```cpp
class MinStack {
public:
    stack<int> s1;
    stack<int> s2;

    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
      s1.push(x);
      if(s2.empty() || x <= s2.top())
        s2.push(x);
    }
    
    void pop() {
      int tmp = s1.top();
      s1.pop();
      if(tmp == s2.top())
        s2.pop();
    }
    
    int top() {
      int tmp = s1.top();
      return tmp;
    }
    
    int getMin() {
      return s2.top();
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