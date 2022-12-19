### 解题思路
此处撰写解题思路
利用Java中的ArrayDeque完成，利用其中的addFirst、removeFirst、isEmpty方法

### 代码

```java
import java.util.ArrayDeque;

class MyStack {

    private ArrayDeque<Integer> stack = new ArrayDeque<Integer>();

    /** Initialize your data structure here. */
    public MyStack() {

    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        stack.addFirst(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return stack.removeFirst();
    }
    
    /** Get the top element. */
    public int top() {
        return stack.getFirst();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return stack.isEmpty();
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