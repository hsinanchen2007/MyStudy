### 解题思路
栈：先进后出，后进先出，利用java中LinkedList完成一端操作。

### 代码

```java
class MyStack {

    private LinkedList<Integer> queue;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {

        queue = new LinkedList<Integer>();
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        queue.addFirst(x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        return queue.removeFirst();
    }

    /**
     * Get the top element.
     */
    public int top() {

        return queue.getFirst();
    }

    /**
     * Returns whether the stack is empty.
     */
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