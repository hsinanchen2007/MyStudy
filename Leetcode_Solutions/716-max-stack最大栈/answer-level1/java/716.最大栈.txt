```
class MaxStack {

    private Queue<Integer> inQueue;
    private Queue<Integer> outQueue;

    /** initialize your data structure here. */
    public MaxStack() {
        inQueue = new LinkedBlockingDeque();
        outQueue = new LinkedBlockingDeque();
    }
    
    public void push(int x) {
        inQueue.add(x);
        while(!outQueue.isEmpty()){
            inQueue.add(outQueue.poll());
        }
        while(!inQueue.isEmpty()){
            outQueue.add(inQueue.poll());
        }
    }
    
    public int pop() {
        return outQueue.poll();
    }
    
    public int top() {
        return outQueue.peek();
    }
    
    public int peekMax() {
        int max = outQueue.peek();
        while(!outQueue.isEmpty()){
            if(outQueue.peek()>max){
                max = outQueue.peek();
            }
            inQueue.add(outQueue.poll());
        }
        while(!inQueue.isEmpty()){
            outQueue.add(inQueue.poll());
        }
        return max;
    }
    
    public int popMax() {
        int max = outQueue.peek();
        int dummmyTimes = 0;
        int times = 0;
        while(!outQueue.isEmpty()){
            if(outQueue.peek()>max){
                max = outQueue.peek();
                times = dummmyTimes;
                inQueue.add(outQueue.poll());
                dummmyTimes++;
            }else{
                inQueue.add(outQueue.poll());
                dummmyTimes++;
            }
        }
        while(times!=0){
            outQueue.add(inQueue.poll());
            times--;
        }
        inQueue.poll();
        while(!inQueue.isEmpty()){
            outQueue.add(inQueue.poll());
        }
        return max;
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
```
