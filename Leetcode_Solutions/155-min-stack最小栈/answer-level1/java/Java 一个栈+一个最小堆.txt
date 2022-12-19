```
package com.huawei.leetcode;

import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;

/**
 * https://leetcode-cn.com/problems/min-stack/
 * @since 2019-11-19
 */
public class MinStack {
    private Stack<Integer> stack = new Stack<>();
    private Queue<Integer> minHeap = new PriorityQueue<>();

    public MinStack() {

    }

    public void push(int x) {
        stack.push(x);
        minHeap.offer(x);
    }

    public void pop() {
        int val = stack.pop();
        minHeap.remove(val);
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return minHeap.peek();
    }

    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        System.out.println(minStack.getMin());   //--> 返回 -3.
        minStack.pop();
        System.out.println(minStack.top());      //--> 返回 0.
        System.out.println(minStack.getMin());   //--> 返回 -2.
    }
}

```
