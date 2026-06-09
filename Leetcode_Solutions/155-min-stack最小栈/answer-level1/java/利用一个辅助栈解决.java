```
class MinStack {
    
    public Stack<Integer> stack1;
    public Stack<Integer> stack2;
    /** initialize your data structure here. */
    public MinStack() {
         stack1 = new Stack();
         stack2 = new Stack();
    }
    
    public void push(int x) {
        stack1.push(x);
        if(stack2.isEmpty() || x <= stack2.peek()){
            stack2.push(x);
        }
        else{
            stack2.push(stack2.peek());
        }
    }
    
    public void pop() {
        stack1.pop();
        stack2.pop();
    }
    
    public int top() {
        return stack1.peek();
    }
    
    public int getMin() {
        return stack2.peek();
    }
}
```
