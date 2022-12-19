***均摊o1复杂度 java实现题解 双栈 出队栈 入队栈 
战胜100%java提交***
![image.png](https://pic.leetcode-cn.com/8817801e64aee2d5091f983e2729fa5a9e6b33c765ef58ce9e689f60ff6beb02-image.png)

class MyQueue {
    private Stack<Integer> in;
    private Stack<Integer> out;
    /** Initialize your data structure here. */
    public MyQueue() {
        in =  new Stack<>();
        out = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        while(!out.isEmpty()){
            in.push(out.pop());
        }
        Stack<Integer> temp = in;
        in = out;
        out = temp;
        
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(out.isEmpty()){
            return in.pop();
        }
        return out.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        if(out.isEmpty()){
            return in.peek();
        }
        return out.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return in.isEmpty() && out.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */