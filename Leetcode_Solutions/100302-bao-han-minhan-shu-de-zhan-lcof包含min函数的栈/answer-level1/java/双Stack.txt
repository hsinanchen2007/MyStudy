### 解题思路
此处撰写解题思路

### 代码

```java
class MinStack {

    /** initialize your data structure here. */
    Stack<Integer> stack = new Stack<>();
    Stack<Integer> min = new Stack<>();
    public MinStack() {

    }
    
    public void push(int x) {
        stack.push(x);
        if(min.isEmpty()){min.push(x);}
        else min.push(Math.min(min.peek(),x));
    }
    
    public void pop() {
        min.pop();
        stack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int min() {
        return min.peek();
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