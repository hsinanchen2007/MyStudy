### 解题思路
使用双端队列来实现栈（先进后出）
push(x): 元素入栈使用双端队列的从头部Push方法；
pop(x):移除栈顶元素使用双端队列pop_front();
top():使用双端队列front(),获取队列中第一个元素，即最近加入的元素
empty():同队列的empty()
### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    /** Push element x onto stack. */
    void push(int x) {
        Q.push_front(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(!Q.empty())
        { int value=Q.front();
            Q.pop_front();
            return value;
        }
        else
        {
            return NULL;
        }
    }
    /** Get the top element. */
    int top() {
        return Q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    }
private:
    std::deque<int> Q;
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