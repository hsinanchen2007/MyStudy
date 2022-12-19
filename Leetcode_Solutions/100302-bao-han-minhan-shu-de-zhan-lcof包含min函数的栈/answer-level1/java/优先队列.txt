### 解题思路

使用小顶堆就可以了。

### 代码

```java
class MinStack {

    Stack<Integer> stack;
    PriorityQueue<Integer> queue;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<>();
        queue = new PriorityQueue<>();
    }

    public void push(int x) {
        stack.push(x);
        queue.add(x);
    }

    public void pop() {
        int val = stack.pop();
        queue.remove(val);
    }

    public int top() {
        return stack.peek();
    }

    public int min() {
        return queue.peek();
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