使用两个栈，一个push栈，一个pop 栈，再用一个 front 记录队首


```
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s;
    stack<int> help_s;
    int front;
    MyQueue() {
    };
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(!s.empty()){
            s.push(x);
        }else if(!help_s.empty()){
            while(!help_s.empty()){
                int temp = help_s.top();
                help_s.pop();
                s.push(temp);
            }
            s.push(x);
        }else{
            s.push(x);
            front = x;
        }
    };
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int output;
        if(!help_s.empty()){
            output = help_s.top();
            help_s.pop();
            if(!help_s.empty()){
                front = help_s.top();
            }
            return output;
        }else if(!s.empty()){
            while(!s.empty()){
                int temp = s.top();
                s.pop();
                help_s.push(temp);
            }
            output = help_s.top();
            help_s.pop();
            if(!help_s.empty()){
                front = help_s.top();
            }
            return output;
        }else{
            return NULL;
        }
    };
    
    /** Get the front element. */
    int peek() {
        if(empty()){
            return NULL;
        }
        return front;
    };
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s.empty() && help_s.empty()){
            return true;
        }
        return false;
    };
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