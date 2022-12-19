### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.Stack;
class MinStack {
 /**
   * initialize your data structure here.
   */
  private Stack<Integer> stack = new Stack<>();
  private Stack<Integer> minStack = new Stack<>();

  public MinStack() {

  }

  public void push(int x) {
    stack.push(x);
    if (minStack.isEmpty() || minStack.peek() >= x) {
      minStack.push(x);
    }
  }

  public void pop() {
    if (stack.isEmpty()) {
      return;
    }
    Integer top = stack.pop();
    if (!minStack.isEmpty() && top.equals(minStack.peek())) {
      minStack.pop();
    }
  }

  public int top() {
    return stack.isEmpty() ? 0 : stack.peek();
  }

  public int getMin() {
    return minStack.isEmpty() ? 0 : minStack.peek();
  }
}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```