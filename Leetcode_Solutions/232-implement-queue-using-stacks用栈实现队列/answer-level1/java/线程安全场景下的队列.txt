题目本身不难, 也挺常见,但是我面试遇到的时候,都是要求实现线程安全下的队列,所以,我在原题目的基础上增加了锁,实现了线程安全下的队列
```
class MyQueue {
    Object transLock = new Object();
    Stack<Integer> input;
    Stack<Integer> output;
    
    /** Initialize your data structure here. */
    public MyQueue() {
         input = new Stack();
         output = new Stack();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        synchronized(transLock){
            input.push(x);
        }
    }
    private void trans(){
        while(input.size() > 0){
            output.push(input.pop());
        }
    }
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (output.size() == 0){
             synchronized(transLock){
                trans();
            }
        }
        return output.pop();
    }
    
    /** Get the front element. */
    public int peek() {
         if (output.size() == 0){
             synchronized(transLock){
                trans();
            }
        }
        return output.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        if(input.size()==0 && output.size()==0)
            return true;
        else
            return false;
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
```
