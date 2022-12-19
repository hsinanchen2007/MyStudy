### 解题思路
利用一个队列实现
push：新元素在入栈时将成为队尾，然后将队列全部元素出队重新依次入队，新元素就变成队首（即栈顶）
pop：pop队首元素
top：即s队首元素front
empty：对队列进行empty查询

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int>* q;
    MyStack() {
         q = new queue<int>;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        this->q->push(x);
        int size = this->q->size();
        while(size  > 1){
            this->q->push(this->q->front());
            this->q->pop();
            size--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = this->q->front();
        this->q->pop();
        return(tmp);
    }
    
    /** Get the top element. */
    int top() {
        return this->q->front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return this->q->empty();
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