在入栈时同时入栈此时栈的最小值，出栈时同时出栈最小值。

![image.png](https://pic.leetcode-cn.com/311dce3abef237ed5d98137ac6ba416db32e7efe404a77ab80e352d1a4dce925-image.png)

其中min1为{value1}中的最小值，min2为{value1,value2}中的最小值，min3为{value1,value2,value3}中的最小值。

```
class MinStack {

    private Stack<Integer> stack;
    int min = Integer.MAX_VALUE;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<>();
    }

    public void push(int x) {
        if(x<min)
            min = x;
        stack.push(x);
        stack.push(min);
    }

    public void pop() {
        if(stack.empty())
            throw new RuntimeException("MinStack is empty");
        stack.pop();
        stack.pop();
        min = stack.empty()?Integer.MAX_VALUE:stack.peek();
    }

    public int top() {
        if(stack.empty())
            throw new RuntimeException("MinStack is empty");
        int temp = stack.pop();
        int top = stack.peek();
        stack.push(temp);
        return top;
    }

    public int getMin() {
        if(stack.empty())
            throw new RuntimeException("MinStack is empty");
        return min;
    }
}
```
