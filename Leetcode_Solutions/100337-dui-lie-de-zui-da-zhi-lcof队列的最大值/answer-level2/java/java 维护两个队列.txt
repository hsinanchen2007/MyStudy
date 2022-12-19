### 解题思路
此处撰写解题思路

### 代码

```java
class MaxQueue {
    //普通队列
    private LinkedList<Integer> queue=new LinkedList();
    //优先队列从大到小
    private PriorityQueue<Integer> priority=new PriorityQueue<>((v1,v2)->v2-v1);
    public MaxQueue() {

    }
    
    public int max_value() {
        if(queue.isEmpty()){
            return -1;
        }
        //获取priority中的第一个元素就是最大值
        return priority.peek();
    }
    
    public void push_back(int value) {
        //两个队列同时添加元素
        queue.add(value);
        priority.add(value);
    }
    
    public int pop_front() {
        if(queue.isEmpty()){
            return -1;
        }
        //删除弹出的元素
        Integer poll=queue.poll();
        priority.remove(poll);
        return poll;
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