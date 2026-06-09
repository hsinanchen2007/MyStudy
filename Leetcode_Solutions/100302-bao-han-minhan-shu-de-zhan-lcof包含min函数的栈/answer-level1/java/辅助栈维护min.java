### 解题思路
此处撰写解题思路
辅助栈维护min
执行用时 :
19 ms
, 在所有 Java 提交中击败了
92.54%
的用户
内存消耗 :
41.5 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class MinStack {
    Stack<Integer> stack1, stack2;
    /** initialize your data structure here. */
    public MinStack() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    
    public void push(int x) {
        stack1.push(x);
        if (stack2 .isEmpty() || stack2.peek() >= x) stack2.push(x);
    }
    
    public void pop() {
        if (stack1.pop().equals(stack2.peek())) stack2.pop();
    }
    
    public int top() {
        return stack1.peek();
    }
    
    public int min() {
        return stack2.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */
```