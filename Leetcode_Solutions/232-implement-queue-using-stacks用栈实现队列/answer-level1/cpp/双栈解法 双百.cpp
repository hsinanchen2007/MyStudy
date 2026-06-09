offer 有道题和这个很像 于是照着改了一下

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> A;
    stack<int> B;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
     A.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(A.empty()&&B.empty()) return -1;
        if(!B.empty())
        {
            
            int n=B.top();
            B.pop();
            return n;
        }
        else
        {
            while(!A.empty())
            {
                B.push(A.top());
                A.pop();
            }
            int n=B.top();
            B.pop();
            return n;
        }
    }
    
    /** Get the front element. */
    int peek() {
    if(A.empty()&&B.empty()) return -1;
        if(!B.empty())
        {
            
            int n=B.top();
            return n;
        }
        else
        {
            while(!A.empty())
            {
                B.push(A.top());
                A.pop();
            }
            int n=B.top();
            return n;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return A.empty()&&B.empty();
    }
};