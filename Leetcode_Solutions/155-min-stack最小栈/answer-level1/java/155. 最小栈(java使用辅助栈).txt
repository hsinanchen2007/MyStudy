```java []
class MinStack {
    private Stack<Integer> data;
    private Stack<Integer> min;

    /** initialize your data structure here. */
    public MinStack() {
        this.data = new Stack<Integer>();
        this.min = new Stack<Integer>();
    }
    
    public void push(int x) {
        data.push(x);
        if(min.size() == 0 || x < min.peek()){
            min.push(x);
        }
        else{
            min.push(min.peek());
        }
    }
    
    public void pop() {
        if(data.size() > 0 && min.size() > 0){
            data.pop();
            min.pop();
        }
    }
    
    public int top() {
        if(data.size() > 0){
            return data.peek();
        }
        else{
            return 0;
        }
    }
    
    public int getMin() {
        if(data.size() > 0 && min.size() > 0){
            return min.peek();
        }
        return 0;
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
