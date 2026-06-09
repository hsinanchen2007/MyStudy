只要是把思路讲清楚，很容易就能实现。

我们新建一个栈，每一项都是一个长度为 2 的数组，数组的第一项储存当前的值，第二项储存最小值，这个最小值是当次元素为栈顶元素时计算的最小值。举个例子。如果我们依次入栈：10，-10，10，-20。那么我们的栈的构造就是：

```
[-20, -20]
[10, -10]
[-10, -10]
[10, 10]
```

明白这个思路就可以很简单的写出代码了，效率也很高，不论是运行时间还是占用空间都是 97% 以上：

```java
import java.util.Stack;

class MinStack {
  private Stack<int []> stack;
  private int _min;

  public MinStack() {
    stack = new Stack<>();
  }

  public void push(int x) {
    if (stack.empty() || _min > x) {
      _min = x;
    }
    stack.push(new int[]{x, _min});
  }

  public void pop() {
    stack.pop();
    if (!stack.isEmpty()) {
      _min = stack.peek()[1];
    }
  }

  public int top() {
    return stack.peek()[0];
  }

  public int getMin() {
    return stack.peek()[1];
  }
}

```