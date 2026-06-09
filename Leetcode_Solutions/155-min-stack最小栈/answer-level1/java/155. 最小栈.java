### 解题思路
此处撰写解题思路

### 代码

```java
class MinStack {

    /** initialize your data structure here. */
    private Stack<Integer> stack;
    private Stack<Integer> minStack; 
   
    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>();
    }
    
    public void push(int x) {
        stack.push(x);
        if(minStack.isEmpty()){
            minStack.push(x);
        }else{
            if(minStack.peek()>=x)
                minStack.push(x);
        }
    }
    
    public void pop() {
        // if(stack.peek()==minStack.peek()) //不知道为什么 这样判断会出错
        //     minStack.pop();
        // stack.pop();

        int pop = stack.pop();
        if(pop==minStack.peek())
            minStack.pop();       
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