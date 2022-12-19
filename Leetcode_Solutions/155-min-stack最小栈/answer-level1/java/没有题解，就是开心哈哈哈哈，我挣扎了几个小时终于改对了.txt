### 解题思路
此处撰写解题思路

### 代码

```java
class MinStack {

    /** initialize your data structure here. */
    Stack<Integer> stack = new Stack<>(); 
    Stack<Integer> minStack = new Stack<>();
    public MinStack() {
    
    }
    
    public void push(int x) {
        if(stack.isEmpty()){
            stack.push(x);
            minStack.push(x);
            
        }else if(!stack.isEmpty()){
            stack.push(x);
            if(x<=minStack.peek()){
                minStack.push(x);
            }
        }
    }
    
    public void pop() {
        if(stack.peek().equals(minStack.peek())){
            minStack.pop();
            stack.pop();
        }else{
            stack.pop();
        }

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