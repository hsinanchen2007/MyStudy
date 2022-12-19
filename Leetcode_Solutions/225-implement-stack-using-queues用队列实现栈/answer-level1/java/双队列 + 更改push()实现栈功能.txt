### 解题思路
使用两个队列加更改push的方法实现栈功能。
- inQuene用来维持出栈顺序，让inQuene一直为空，保证每次有新元素加入时可以直接进入队首。
- outQuene用来弹出元素，在inQuene接收完新元素后，将outQuene中的元素加入inQuene中维持出栈顺序，然后再把inQuene中的元素加入outQuene保证outQuene的弹出顺序。

### 代码

```java
class MyStack {

    private Queue<Integer> inQuene;
    private Queue<Integer> outQuene;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {
        inQuene = new LinkedList<>();
        outQuene = new LinkedList<>();
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        inQuene.add(x);

        while (!outQuene.isEmpty()) {
            inQuene.add(outQuene.poll());
        }

        while (!inQuene.isEmpty()) {
            outQuene.add(inQuene.poll());
        }
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        return outQuene.poll();
    }

    /**
     * Get the top element.
     */
    public int top() {
        return outQuene.peek();
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return outQuene.isEmpty();
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