有人能解答一下我写的pop_front方法错在哪里了吗（注释的写法为正确写法）
``` java
class MaxQueue {
    LinkedList<Integer> queue;
    LinkedList<Integer> deque;
    public MaxQueue() {
        queue = new LinkedList<Integer>();
        deque = new LinkedList<Integer>();
    }
    
    public int max_value() {
        if(queue.isEmpty()) return -1;
        else return deque.peekFirst();
    }
    
    public void push_back(int value) {
        queue.offer(value);
        while(!deque.isEmpty()&&deque.peekLast()<value)
            deque.pollLast();
        deque.addLast(value);
    }
    
    public int pop_front() {
        if(queue.isEmpty()) return -1;
         if(deque.peekFirst()==queue.peekFirst())
             deque.pollFirst();
         return queue.pollFirst();
      /*  int res = queue.peekFirst();
        queue.pollFirst();
        if(res==deque.peekFirst())
            deque.pollFirst();
        return res;*/
    }
}
```

