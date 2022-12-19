Java:
```
class MyQueue {
    Stack<Integer> p=new Stack<>();
    Stack<Integer> q=new Stack<>();
    /** Initialize your data structure here. */
    public MyQueue() {

    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        while(!p.empty()){
            q.push(p.lastElement());
            p.pop();
        }
        p.push(x);
        while(!q.empty()){
            p.push(q.lastElement());
            q.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        int res=p.lastElement();
        p.pop();
        return res;
    }

    /** Get the front element. */
    public int peek() {
        return p.lastElement();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return p.empty();
    }
}
```

C++:
```
class MyQueue {
public:
    stack<int> p,q;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!p.empty()){
            q.push(p.top());
            p.pop();
        }
        p.push(x);
        while(!q.empty()){
            p.push(q.top());
            q.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res=p.top();
        p.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return p.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return p.size()==0;
    }
};
```
