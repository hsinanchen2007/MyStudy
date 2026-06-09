###请问这是什么Bug? 
我的pop_front函数，为什么if判断改成if(queue1.peek()==queue2.peekFirst())就无法判断？？


### 代码

```java
class MaxQueue {
    Queue<Integer> queue1;
    Deque<Integer> queue2;
    public MaxQueue() {
        queue1=new LinkedList<Integer>();
        queue2=new LinkedList<Integer>();
    }
    
    public int max_value() {
        if(!queue2.isEmpty())
        {return queue2.peek();}
        else return -1;
    }
    
    public void push_back(int value) {
        
        while(!queue2.isEmpty()&&queue2.peekLast()<value)
        {
            queue2.pollLast();
        }
        queue2.offerLast(value);
        queue1.offer(value);
    }
    
    public int pop_front() {
        if(!queue1.isEmpty())
        {
            int temp=queue1.peek();
            if(temp==queue2.peekFirst())
            queue2.poll();
            queue1.poll();
        return temp;}
        else return -1;
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
```