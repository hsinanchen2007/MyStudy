### 解题思路
这里用到了小顶堆来获得最小值。

### 代码

```java
class MinStack {

    PriorityQueue<Integer> priorityQueue;
    Stack<Integer> stack;

    public MinStack() {
        stack = new Stack<>();
        priorityQueue = new PriorityQueue<>();
    }

    public void push(int x) {
        stack.push(x);
        priorityQueue.add(x);

    }

    public void pop() {
        int remove = stack.pop();
        priorityQueue.remove(remove);
    }

    public int top() {
        return stack.peek();
    }

    public int min() {
        return priorityQueue.peek();
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