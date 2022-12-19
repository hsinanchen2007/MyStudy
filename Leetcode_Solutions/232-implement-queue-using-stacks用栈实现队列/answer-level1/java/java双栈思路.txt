### 解题思路
此处撰写解题思路

### 代码

```java
class MyQueue {
    Stack<Integer> stack ;
    Stack<Integer> helper ;
    /** Initialize your data structure here. */
    public MyQueue() {
        stack = new Stack<>();
        helper = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        stack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(helper == null || helper.isEmpty()){
            while (!stack.isEmpty()) helper.push(stack.pop());
        }
        return helper.pop();
    }

    /** Get the front element. */
    public int peek() {
        if(helper == null || helper.isEmpty()){
            while (!stack.isEmpty()) helper.push(stack.pop());
        }
        return helper.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        if(helper != null && stack != null && helper.isEmpty() && stack.isEmpty()) return true;
        return false;
    }
}
```