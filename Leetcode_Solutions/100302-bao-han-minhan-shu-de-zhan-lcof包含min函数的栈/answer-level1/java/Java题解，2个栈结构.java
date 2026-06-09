class MinStack {
    Stack<Integer> s1;
    Stack<Integer> s2;
    /** initialize your data structure here. */
    public MinStack() {
        s1 = new Stack<Integer>();  //存储所有元素的值
        s2 = new Stack<Integer>();  // 存储最小元素的值
    }
    
    public void push(int x) {
        s1.push(x);
        if(s2.isEmpty()){
            s2.push(x);
        }else if(x<=s2.peek()){
            s2.push(x);
        }
    }
    
    public void pop() {
        if(s1.peek() <= s2.peek()){
            s1.pop();
            s2.pop();
        }else{
            s1.pop();
        }
    }
    
    public int top() {
        return s1.peek();
    }
    
    public int min() {
        return s2.peek();
    }
}