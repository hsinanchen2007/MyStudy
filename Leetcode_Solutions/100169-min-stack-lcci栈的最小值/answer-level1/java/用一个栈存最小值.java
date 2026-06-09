### 解题思路
此处撰写解题思路

### 代码

```java
class MinStack {

    Stack<Integer> stack;
    Stack<Integer> stackMin;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<>();
        stackMin = new Stack<>();
    }
    
    public void push(int number) {
        stack.push(number);
        if(stackMin.isEmpty()) {
            stackMin.push(number);
        } else {
            stackMin.push(Math.min(number, stackMin.peek()));
        }
    }
    
    public void pop() {
        stackMin.pop();
        stack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return stackMin.peek();
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