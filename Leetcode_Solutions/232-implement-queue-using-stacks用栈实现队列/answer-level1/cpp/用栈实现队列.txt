```
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        _s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> tmp;
        while (!_s1.empty()) {
            tmp.push(_s1.top()); 
            _s1.pop();
        }
        int result = tmp.top();
        tmp.pop();
        while (!tmp.empty()) {
            _s1.push(tmp.top());
            tmp.pop();
        }
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> tmp;
        while (!_s1.empty()) {
            tmp.push(_s1.top());  
            _s1.pop();
        }
        int result = tmp.top();
        while (!tmp.empty()) {
            _s1.push(tmp.top());
            tmp.pop();
        }
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _s1.empty();
    }
private:
    stack<int> _s1;
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
