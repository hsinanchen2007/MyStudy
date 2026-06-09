### 解题思路
使用队列实现栈，思路简单
q1是操作队列，q2是暂存队列，每次pop或者top时，将q1除最后一个元素外暂存进q2，然后出栈或者展示，再将q2中的元素移动回q1

### 代码

```java
// package com.leetcode.practices.implementStackUsingQueues;

import java.util.LinkedList;
import java.util.Queue;

/**
 * https://leetcode-cn.com/problems/implement-stack-using-queues/
 * 
 */
class MyStack {

    Queue<Integer> q1;

    Queue<Integer> q2;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {
        q1 = new LinkedList<>();
        q2 = new LinkedList<>();
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        q1.add(x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        while (q1.size() != 1) {
            q2.add(q1.poll());
        }
        int retInt = q1.poll();

        while (q2.size() > 0) {
            q1.add(q2.poll());
        }
        return retInt;
    }

    /**
     * Get the top element.
     */
    public int top() {
        while (q1.size() != 1) {
            q2.add(q1.poll());
        }
        int retInt = q1.poll();

        q2.add(retInt);

        while (q2.size() > 0) {
            q1.add(q2.poll());
        }
        return retInt;
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return q1.isEmpty();
    }
}
```