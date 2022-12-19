```
class MinStack {
    int value;
    MinStack next;
    int minimum;

    /** initialize your data structure here. */
    public MinStack() {
        minimum = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        MinStack obj = new MinStack();
        obj.next = this.next;
        obj.value = this.value;
        obj.minimum = this.minimum;
        value = x;
        next = obj;
        minimum = (x > obj.minimum) ? obj.minimum : x;
    }
    
    public void pop() {
        value = next.value;
        minimum = next.minimum;
        next = next.next;       
    }
    
    public int top() {
        return value;
    }
    
    public int getMin() {
        return minimum;
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
