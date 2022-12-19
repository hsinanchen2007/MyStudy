### 解题思路
队列是先进先出的，栈是先进后出的；
为了让最后入队列的元素x先出，可以将队列中除了位于队尾的元素x外的所有元素先出队列，然后再入队列；此时，元素x位于队首；
依此循环，就实现了先进后出的顺序；

### 代码

```java
class MyStack {
    private Queue<Integer> queue = new LinkedList<Integer>();
    /** Initialize your data structure here. */
    public MyStack() {
        
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        queue.add(x);
        int cd = queue.size();
        while (cd > 1) {
            queue.add(queue.poll());
            cd--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return queue.remove();
    }
    
    /** Get the top element. */
    public int top() {
        return queue.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
```