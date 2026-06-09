### 解题思路
此处撰写解题思路
两个栈来回倒腾，懒得用数组或者链接去弄了，直接jdk自带的stack搞了
### 代码

```java
class MyQueue {

    /**
     * Initialize your data structure here.
     */
    Stack<Integer> storeStack;
    Stack<Integer> popStack;

    public MyQueue() {
        storeStack = new Stack<>();
        popStack = new Stack<>();
    }

    /**
     * Push element x to the back of queue.
     */
    public void push(int x) {
        while (!popStack.empty()) {
            storeStack.push(popStack.pop());
        }
        storeStack.push(x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop() {
        while (!storeStack.empty()) {
            popStack.push(storeStack.pop());
        }
        return popStack.pop();
    }

    /**
     * Get the front element.
     */
    public int peek() {
        while (!storeStack.empty()) {
            popStack.push(storeStack.pop());
        }
        return popStack.peek();
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty() {
        return storeStack.empty() && popStack.empty();
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