### 解题思路
一个目标堆栈，一个源头堆栈。
堆栈一倒腾就成了队列。

### 代码

```java
class MyQueue {
    private Stack<Integer> srcStack = new Stack<>();
    private Stack<Integer> desStack = new Stack<>();


    /**
     * Initialize your data structure here.
     */
    public MyQueue() {

    }

    /**
     * Push element x to the back of queue.
     */
    public void push(int x) {
        srcStack.push(x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop() {
        if (empty()){
            return -1;
        }
        if (!desStack.isEmpty()) {
            return (int) desStack.pop();
        } else {
            while (!srcStack.empty()) {
                desStack.push(srcStack.pop());
            }
            return desStack.pop();
        }
    }

    /**
     * Get the front element.
     */
    public int peek() {
        if (empty()){
            return -1;
        }
        if (!desStack.isEmpty()) {
            return (int) desStack.peek();
        } else {
            while (!srcStack.empty()) {
                desStack.push(srcStack.pop());
            }
            return (int) desStack.peek();
        }
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty() {
        return srcStack.isEmpty() && desStack.isEmpty();
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