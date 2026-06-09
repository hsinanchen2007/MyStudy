## 思路
定义两个栈，入队放入stack1中，出队从stack2，如果stack2为空，则将stack1中元素弹出放入stack2中。
## 代码
```c++
class MyQueue {
    stack<int> stack1;
    stack<int> stack2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {        
        if (stack2.empty()) {
             while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();                
            }
        }            
        int a = stack2.top();
        stack2.pop();        
        return a;
    }
    
    /** Get the front element. */
    int peek() {        
        if (stack2.empty()) {
             while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();                
            }
        }            
        return stack2.top();             
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};
```
