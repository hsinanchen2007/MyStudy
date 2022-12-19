### 解题思路
**新手小白**
- 栈的特点：先入后出；队列的特点：先入先出；
- 使用queue的push()实现push()功能；
- 实现pop()功能时，新建queue保存其他数据；
- top()同理；
- 使用queue的empty()实现empty()判断。

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int>* head;

    MyStack() {
        this->head = new queue<int>;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        this->head->push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int>* tmp = new queue<int>; //使用new创建空间
        int value;
        while(this->head->size()>1){
            tmp->push(head->front());
            head->pop();
        }
        value = head->front();
        head->pop();
        head = tmp;
        return value;
    }
    
    /** Get the top element. */
    int top() {
        queue<int>* tmp = new queue<int>;
        int value;
        while(this->head->size()>1){
            tmp->push(head->front());
            head->pop();
        }
        value = head->front();
        head->pop();
        head = tmp;
        head->push(value);
        return value;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return this->head->empty();
    }
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