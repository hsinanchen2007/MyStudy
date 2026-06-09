### 解题思路
跟着精选题解的思路，使用一个帮助的栈，这个栈的栈顶元素就是存储进来的栈中的最小值，“以空间换取时间”。

### 代码

```java
class MinStack {

    /** initialize your data structure here. */
    private Stack<Integer> stack;
    private Stack<Integer> helpStack;

    public MinStack() {
        stack = new Stack();
        helpStack = new Stack();
    }

    public void push(int x) {
        stack.add(x);
        //保证helpStack中的栈顶元素就是stack栈中的最小值
        if(helpStack.isEmpty() || helpStack.peek() >= x)
            helpStack.add(x);
        else
            helpStack.add(helpStack.peek());

    }

    public void pop() {
        if(!stack.isEmpty()){
            helpStack.pop();
            stack.pop();
        }else
            throw new RuntimeException("栈为空，无法删除");
    }

    public int top() {
        if(stack.isEmpty())
           throw new RuntimeException("栈为空格，无法获取栈顶元素");
        return stack.peek();
    }

    public int getMin() {
        if(stack.isEmpty())
            throw new RuntimeException("栈为空");
        return helpStack.peek();
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