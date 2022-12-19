### 解题思路
设置一个队列
维护一个辅助-单调递减队列

### 代码

```java
class MaxQueue {
  
    //队列值
    Queue<Integer> queue;
    
    //辅助队列 - 单调队列
    Deque<Integer> helper;

    public MaxQueue() {
        this.queue  = new ArrayDeque();
        this.helper = new ArrayDeque();
    }
    
    public int max_value() {
        if (helper.isEmpty()) {
            return -1;
        }
        return helper.peek();
    }
    
    public void push_back(int value) {
        queue.offer(value);
        while(helper.size() > 0 && helper.peekLast() < value){
            helper.pollLast();  //将helper队尾小于value的元素删掉
        }
        helper.offerLast(value);  //将value放在helper队尾
    }
    
    public int pop_front() {
        int tmp = queue.size() > 0 ? queue.poll() : -1;  //获得队首元素
        if(helper.size() > 0 && tmp == helper.peek()){
            helper.poll();  //如果出队的元素是当前最大值，将deq的队首出队
        }
        return tmp;
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