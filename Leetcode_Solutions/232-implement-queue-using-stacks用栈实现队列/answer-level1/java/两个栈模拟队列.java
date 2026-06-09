### 解题思路
两个栈模拟队列，可以画个图加深理解。

### 代码

```java
class MyQueue {

    Stack<Integer> stackIn;
    Stack<Integer> stackOut;
    /** Initialize your data structure here. */
    public MyQueue() {
        stackIn = new Stack<>();
        stackOut = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        stackIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        while (!stackIn.isEmpty()){
            stackOut.push(stackIn.pop());
        }
        int result = stackOut.pop();
        while (!stackOut.isEmpty()){
            stackIn.push(stackOut.pop());
        }
        return result;
    }

    /** Get the front element. */
    public int peek() {
        while (!stackIn.isEmpty()){
            stackOut.push(stackIn.pop());
        }
        int result = stackOut.peek();
        while (!stackOut.isEmpty()){
            stackIn.push(stackOut.pop());
        }
        return result;
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stackIn.isEmpty();
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