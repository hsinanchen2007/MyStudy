### 解题思路
问题的难点在于均摊复杂度为O(1);
插入、删除 －－ 普通队列都可以O(1)实现，但是此时，获取maxValue,要经过查找，无序的队列，O(n);
maxVaule 需要保证插入、删除队列元素后的准确性。
如果只记录maxValue，插入肯定没问题的，每次插入比较一下。
关键在于删除元素时候：
   1.一旦maxValue删除，那么最大值删除后，根据删除顺序的接下来的最大值也必须记录下来，否则会找不到接下来的队列的最大值。
    比如 1，3，10，5，4，队列入队，此时最大值 10， 出队列顺序 1，3，10，且 10 出去之后，必须知道目前最大值是 5.
   2.所以单独存储一个变量maxVaule肯定满足不了要求，我们需要引入队列，这个队列必须单调有序，比如刚才的 1，3，10，5，4，
我们这个maxValue队列必须存储10，5，4 才满足要求。
    这里大家估计明白了，需要的队列，必须两端可以操作，因为：
    原 1， maxValue队列：1
    原 1，3， maxValue队列：删除 1，入 3
    原 1，3，10 maxValue队列：删除3， 入 10
    原 1，3，10，5 maxValue队列 入 5 －－ 10，5
    。。。。。。
顾而：获取maxVaule要引入额外的存储，引入虑双端队列－头尾皆可插入、删除。


### 代码

```java
class MaxQueue {

     private Queue<Integer> queue = new LinkedList<>();

     private Deque<Integer> deque = new ArrayDeque<>();

    public MaxQueue() {

    }
    
    public int max_value() {

        if(deque.size() == 0 || queue.size() ==0){
            return -1;
        }

        return deque.peekFirst();
    }
    
    public void push_back(int value) {

        queue.add(value);

        while(!deque.isEmpty() && deque.getLast() < value){
            deque.removeLast();
        }

        deque.addLast(value);

    }
    
    public int pop_front() {
        if(queue.size() == 0){
            return  -1;
        }

        int front = queue.poll();

        if(front == deque.peekFirst()){
            deque.pollFirst();
        }

        return front;
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