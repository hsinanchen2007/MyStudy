### 解题思路

栈是先进后出，而队列是先进先出。
所以，通过两个栈来回倒，可实现队列效果。


### 代码

```java
class MyQueue {

    private Stack<Integer> forwordstack;
    private Stack<Integer> backwordStack;
    /** Initialize your data structure here. */
    public MyQueue() {
        forwordstack = new Stack<>();
        backwordStack = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        if(backwordStack.empty()) {
            forwordstack.push(x);
        } else {
            while(!backwordStack.empty()) {
                forwordstack.push(backwordStack.pop());
            }
            forwordstack.push(x);
        }
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        while(!forwordstack.empty()) {
            backwordStack.push(forwordstack.pop());
        }
        if(backwordStack.empty()) return -1;
        return backwordStack.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        while(!forwordstack.empty()) {
            backwordStack.push(forwordstack.pop());
        }
        if(backwordStack.empty()) return -1;
        return backwordStack.peek();
    }
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return forwordstack.empty() && backwordStack.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
```