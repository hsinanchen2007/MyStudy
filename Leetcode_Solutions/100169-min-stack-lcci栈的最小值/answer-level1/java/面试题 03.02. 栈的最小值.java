### 解题思路
注意 x<=minStack.peek()； 等于号很重要

### 代码

```java
class MinStack {
    private Stack<Integer> stack=new Stack<Integer>();
    private Stack<Integer> minStack=new Stack<Integer>();
    int min=0;
    /** initialize your data structure here. */
    public MinStack() {

    }
    
    public void push(int x) {
        //两个栈都为空
        stack.push(x);
        if(minStack.isEmpty()||x<=minStack.peek()){
            minStack.push(x);
        }
      
    }
    
    public void pop() {
        int x=stack.pop();
        if(x==minStack.peek()){
            minStack.pop();
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        if(minStack.isEmpty()){
            return 0;
        }
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