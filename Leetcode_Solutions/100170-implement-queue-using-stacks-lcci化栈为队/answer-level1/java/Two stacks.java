### 解题思路
Use second stack to reverse the order of the elements;

### 代码

```java
class MyQueue {
    private Stack<Integer> stackNewest;
    private Stack<Integer> stackOldest;
    /** Initialize your data structure here. */
    public MyQueue() {
        this.stackNewest = new Stack<>();
        this.stackOldest = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stackNewest.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        shiftStack();
        return stackOldest.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        shiftStack();
        return stackOldest.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stackNewest.isEmpty() && stackOldest.isEmpty();
    }

    /** Move elements from stackNewest to stackOldest */
    private void shiftStack() {
        if(stackOldest.isEmpty()) {
            while (!stackNewest.isEmpty()) {
                stackOldest.push(stackNewest.pop());
            }
        }
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