### 解题思路

queue.push()  --> dataStack.push()
queue.pop()   --> 当assistStack不为空，对应assistStack.pop()。否则，需要把dataStack（数据栈）出栈元素到assistStack辅助栈，再执行assistStack.pop()
queue.peek()  --> 原理类似于queue.pop()
queue.empty() --> dataStack和assistStack都为空，则返回为空；否则为非空。
### 代码

```cpp
class MyQueue {
private:
    stack<int> dataStack;
    stack<int> assistStack;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        dataStack.push(x);       
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!assistStack.empty()){
            int popElem = assistStack.top();
            assistStack.pop();
            return popElem;
        }
        else{
            if(dataStack.empty()){
                throw runtime_error("Stack is Empty!!!");
            }
            while(!dataStack.empty()){
                assistStack.push(dataStack.top());
                dataStack.pop();
            }
            int tValue = assistStack.top();
            assistStack.pop();
            return tValue;
        }       
    }
    
    /** Get the front element. */
    int peek() {
        if(!assistStack.empty()){
            return assistStack.top();
        }
        else{
            if(dataStack.empty()){
                throw runtime_error("Stack is Empty!!!");
            }
            else{
                while(!dataStack.empty())
                {                   
                    assistStack.push(dataStack.top());
                    dataStack.pop();
                } 
                return  assistStack.top();         
            }
        }    
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return assistStack.empty() && dataStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```