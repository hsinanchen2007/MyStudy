### 解题思路
1.使用两个栈，一个栈是正常的栈，第二个栈存放此刻第一个栈内元素的最小元素，所以第二栈的栈顶永远是此时栈内元素中最小的元素。

### 代码

```cpp
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty()){
            s2.push(x);
        }
        else{
            int t = s2.top();
            s2.push((x < t) ? x : t);
        }
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }

    int top(){
        return s1.top();
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