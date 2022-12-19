队首元素的相关操作，两个stack来回倒一下就行了

代码：
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> sk;
        while (s.size() > 1) {
            sk.push(s.top());
            s.pop();
        }
        int ans = s.top();
        s.pop();
        while (sk.size()) {
            s.push(sk.top());
            sk.pop();
        }
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> sk;
        while (s.size() > 1) {
            sk.push(s.top());
            s.pop();
        }
        int ans = s.top();
        while (sk.size()) {
            s.push(sk.top());
            sk.pop();
        }
        return ans;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};