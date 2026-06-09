### 解题思路
重点在于pop和push操作时的max_value维护问题；需要注意一点，如果较大值后入队列，那么前面记录的较小值均可移除（因为在较大值面前，较小值永无出头之日）
### 代码

```java
class MaxQueue {

    //用于模拟队列，用来保存数据
    private List<Integer> queue=new ArrayList<>();
    //用于模拟双端队列，来存储最大值
    private List<Integer> deque=new ArrayList<>();
    
    public MaxQueue() {

    }
    
    public int max_value() {
        //deque的第一个值即为总体的最大值
        return deque.isEmpty()?-1:deque.get(0);
    }
    
    public void push_back(int value) {
        while(!deque.isEmpty() && value>=deque.get(deque.size()-1)){
            //根据队列的先进先出原理，如果后面进的数比前面的都大，那么前面的数总不能成为最大数，故而可以直接移除（即前面的比当前值小的数永无出头之日）
            //将之称之deque，也是因为此处需要在队列首端移除数据
            deque.remove(deque.size()-1);
        }
        queue.add(value);
        deque.add(value);
    }
    
    public int pop_front() {
        if(queue.isEmpty()){
            return -1;
        } 
        if(queue.get(0).equals(deque.get(0))){
            deque.remove(0);
        }
        return queue.remove(0);
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