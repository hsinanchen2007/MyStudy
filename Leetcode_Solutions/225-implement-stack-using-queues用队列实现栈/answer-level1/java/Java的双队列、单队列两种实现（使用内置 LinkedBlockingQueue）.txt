说明：
1 只针对每次push做处理，还有一种使用pop的方式未实现
2 单队列的思路还是比较奇特的（循环使用），很有意思（平常应该也会遇到类似场景），反过来栈就没办法用一个

双队列实现

```java
public class StackByQueue {

    private Queue<Integer> inQueue;
    private Queue<Integer> outQueue;

    /**
     * Initialize your data structure here.
     */
    public StackByQueue() {
        inQueue = new LinkedBlockingQueue<>();
        outQueue = new LinkedBlockingQueue<>();
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        inQueue.add(x);
        while (!outQueue.isEmpty()) {
            inQueue.add(outQueue.poll());
        }
        while (!inQueue.isEmpty()) {
            outQueue.add(inQueue.poll());
        }
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        return outQueue.poll();
    }

    /**
     * Get the top element.
     */
    public int top() {
        return outQueue.peek();
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return outQueue.isEmpty();
    }

}
```

单队列实现

```java
public class StackByOneQueue {

    private Queue<Integer> queue;

    /**
     * Initialize your data structure here.
     */
    public StackByOneQueue() {
        queue = new LinkedBlockingQueue<>();
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        int count = queue.size();

        queue.add(x);
        while (count > 0) {
            queue.add(queue.poll());
            count--;
        }
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        return queue.poll();
    }

    /**
     * Get the top element.
     */
    public int top() {
        return queue.peek();
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return queue.isEmpty();
    }

}
```