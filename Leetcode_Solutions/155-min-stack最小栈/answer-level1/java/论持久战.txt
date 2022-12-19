```
class MinStack {
    private Stack<Integer> valueStack = new Stack<>() ;
    private Stack<Integer> minStack = new Stack<>() ;

    /** initialize your data structure here. */
    public MinStack() {
        
    }
    
    public void push(int x) {
        valueStack.push(x) ;
        if (minStack.isEmpty() || x <= minStack.peek() )
            minStack.push(x) ;
    }
    
    public void pop() {
        int t = valueStack.pop() ;
        if (t == minStack.peek())
            minStack.pop() ;
    }
    
    public int top() {
        return valueStack.peek() ;
    }
    
    public int getMin() {
        return minStack.peek() ;
    }
}
```
