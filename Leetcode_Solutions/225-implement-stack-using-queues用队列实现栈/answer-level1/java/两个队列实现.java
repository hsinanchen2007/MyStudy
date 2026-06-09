### 解题思路
很经典的题目，用两个队列即可实现栈操作。
1. 只是每次pop时需要整体把一个队列复制到另外一个队列，比较耗时。
2. 用一个成员变量表示top值

### 代码

```java


import java.util.LinkedList;
import java.util.Queue;

class MyStack {

    private Queue<Integer> firstQueue;
    private Queue<Integer> secondQueue;
    private int top;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {
        firstQueue = new LinkedList<>();
        secondQueue = new LinkedList<>();
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        top = x;
        firstQueue.add(x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        while (firstQueue.size() > 1) {
            top = firstQueue.remove();
            secondQueue.add(top);
        }
        int res = firstQueue.remove();
        firstQueue = secondQueue;
        secondQueue = new LinkedList<>();
        return res;
    }

    /**
     * Get the top element.
     */
    public int top() {
        return top;
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return firstQueue.isEmpty();
    }

}

```