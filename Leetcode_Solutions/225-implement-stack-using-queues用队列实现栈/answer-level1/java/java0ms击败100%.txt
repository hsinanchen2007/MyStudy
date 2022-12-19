思路，双队列构成一个“环”
```
class MyStack {
	private Queue<Integer> queue = new LinkedList<Integer>();
    private Queue<Integer> tmp = new LinkedList<Integer>();
    /** Initialize your data structure here. */
    public MyStack() {
        
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        queue.add(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
    	int a = 0;
    	
        while(true){
            a = queue.remove();
            if(!queue.isEmpty())
                tmp.add(a);
            else break;
        }
        while(!tmp.isEmpty())
            queue.add(tmp.remove());
        
        return a;
    }
    
    /** Get the top element. */
    public int top() {
    	int a = 0;
    	
        while(!queue.isEmpty()){
            a = queue.poll();
            tmp.add(a);
        }
        while(!tmp.isEmpty())
            queue.add(tmp.poll());
        
        return a;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
    	return queue.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
```
