`class MinStack {


    //用动态数组实现
    //一个数组为栈  
    ArrayList<Integer> stack;

    //另一个数组存最小值
    ArrayList<Integer> s_min;
    
    /** initialize your data structure here. */
    public MinStack() {
        this.stack = new ArrayList<Integer>();
        this.s_min = new ArrayList<Integer>();
    }
    
    public void push(int x) {
        if(stack.size()==0||x<=s_min.get(s_min.size()-1)){//这里的等号很重要，否则最小值会出错
            s_min.add(x);
        }
        stack.add(x);        
    }
    
    public void pop() {
        if(stack.size()==0) return;//栈为空
        if(this.top()==s_min.get(s_min.size()-1))
            s_min.remove((s_min.size()-1));
        stack.remove(stack.size()-1);
    }
    
    public int top() {
        return stack.get(stack.size()-1);
    }
    
    public int getMin() {
        return s_min.get(s_min.size()-1);
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */`