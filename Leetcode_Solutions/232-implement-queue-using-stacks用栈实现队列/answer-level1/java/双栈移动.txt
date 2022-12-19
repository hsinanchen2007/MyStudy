```java
class MyQueue {
    
    private Stack<Integer> stack ;
    /** Initialize your data structure here. */
    public MyQueue() {
        this.stack = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        this.stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(this.empty()){
            throw new IllegalArgumentException("no item");
        }
        Stack<Integer> temp = new Stack<>();
        while(this.stack.size()>1)
            temp.push(this.stack.pop());
        int element = this.stack.pop();
        while(temp.size()>0)
            this.stack.push(temp.pop());
        return element;
    }
    
    /** Get the front element. */
    public int peek() {
        if(this.empty()){
            throw new IllegalArgumentException("no item");
        }
        Stack<Integer> temp = new Stack<>();
        while(this.stack.size()>1)
            temp.push(this.stack.pop());
        int element = this.stack.peek();
        while(temp.size()>0)
            this.stack.push(temp.pop());
        return element;
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return this.stack.isEmpty();
    }
}
```