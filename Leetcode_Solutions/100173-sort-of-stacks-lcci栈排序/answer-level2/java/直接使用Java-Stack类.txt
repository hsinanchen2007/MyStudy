### 解题思路

实现sort方法，完成最小值浮在栈顶

### 代码

```java
class SortedStack {

    private Stack<Integer> stack;
    public SortedStack() {
        stack = new Stack<>();
    }
    
    public void push(int val) {
        stack.push(val);
    }
    
    public void pop() {
        if(stack.empty()) return;
        stack.sort((n1, n2) -> {
            return n2 - n1;
        });
        stack.pop();
    }
    
    public int peek() {
        if(stack.empty()) return -1;
        stack.sort((n1, n2) -> {
            return n2 - n1;
        });
        return stack.peek();
    }
    
    public boolean isEmpty() {
        return stack.empty();
    }
}

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack obj = new SortedStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.isEmpty();
 */
```