class CustomStack {

    Deque<Integer> stack1;
    Deque<Integer> stack2;
    int maxSz;
    int Sz;
    public CustomStack(int maxSize) {
        stack1 = new ArrayDeque<>();
        stack2 = new ArrayDeque<>();
        maxSz = maxSize;
        Sz = 0;
    }
    
    public void push(int x) {
        if(Sz+1<=maxSz){
            Sz++;
            stack1.push(x);
        }
    }
    
    public int pop() {
        if(stack1.isEmpty())
            return -1;
        Sz--;
        return stack1.pop();
    }
    
    public void increment(int k, int val) {
        while(stack1.size()>k){
            stack2.push(stack1.pop());
        }
        
        while(!stack1.isEmpty()){
            stack2.push(stack1.pop()+val);
        }
        
        while(!stack2.isEmpty()){
            stack1.push(stack2.pop());
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */