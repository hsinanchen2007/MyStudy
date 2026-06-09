```
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        _new.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        shiftStack();
        int val = _old.top();
        _old.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        shiftStack();
        return _old.top();
    }
    
    void shiftStack() {
        if(!_old.empty()) return;
        while(!_new.empty()) {
            _old.push(_new.top());
            _new.pop();
        }
    }    
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _old.empty() && _new.empty();
    } 
private:
    stack<int> _new, _old;
};
```
