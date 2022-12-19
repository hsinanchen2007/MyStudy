### 解题思路
用两个队列来实现，入栈效率较低，时间复杂度 O(n)，其他操作时间复杂度 O(1)。

### 代码

```java
class MyStack {

    private Queue<Integer> q1 = new LinkedList<>();
    private Queue<Integer> q2 = new LinkedList<>();
    private int topVal = 0;
    
    /** Push element x onto stack. */
    public void push(int x) {
        q1.add(x);
        topVal = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        while (q1.size() > 1) {
            int val = q1.poll();
            q2.add(val);
            topVal = val;
        }
        Queue<Integer> tmpQueue = q1;
        q1 = q2;
        q2 = tmpQueue;
        return q2.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return topVal;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q1.isEmpty();
    }
}

```