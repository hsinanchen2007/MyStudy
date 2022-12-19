### 解题思路
minStack的栈顶用来存放当前栈的最小值。
由于只有push和pop能改变栈中的最小值，所以只需要在这两个操作中维护minStack即可
push操作，如果新加入的元素比之前的最小值小，那么压入minstack栈顶，代表当前栈的最小值
pop操作，如果pop的是最小值，那么需要将minStack的栈顶弹出，将minStack中第二个元素变成栈顶，表示当前栈的最小值。

### 代码

```java
class MinStack {
    Stack<Integer> stack;
    Stack<Integer> minStack;
    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>();
    }

    public void push(int x) {
        stack.push(x);
        if (minStack.empty() || minStack.peek() >= x) {
            minStack.push(x);
        }
    }

    public void pop() {
        if (stack.peek().equals(minStack.peek()) ) {
            minStack.pop();
        }
        stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return minStack.peek();
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