### 解题思路
特别注意的是，pop的时候，应该立马从大顶堆中删除此元素值。一开始写的语句是该元素值等于堆顶时才删除，忽略了这点。

### 代码

```java
class MaxQueue {
    Queue<Integer> dataqueue;
    PriorityQueue<Integer> maxheap;
    public MaxQueue() {
        dataqueue = new LinkedList<Integer>();
        maxheap = new PriorityQueue<Integer>((o1, o2) -> o2 - o1);
    }
    
    public int max_value() {
        if(dataqueue.isEmpty()){
            return -1;
        }else{
            return maxheap.peek();
        }
    }
    
    public void push_back(int value) {
        dataqueue.add(value);
        maxheap.add(value);
    }
    
    public int pop_front() {
        if(dataqueue.isEmpty()){
            return -1;
        }else{
            int val = dataqueue.poll();
            if(!maxheap.isEmpty()){
                maxheap.remove(val);
            }
            return val;
        }
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