
```
class KthLargest {
     //创建一个K大小的优先级队列，即最小堆。因为是int类型，默认从小到大。
    private PriorityQueue<Integer> queue;
    private int limit;
    public  KthLargest(int k, int[] nums) {
        queue = new PriorityQueue<Integer>(k);
        limit = k;
        for(int num:nums){
            add(num);
        }
    }
    
    public int add(int val) {
        if(queue.size()<limit){
            queue.add(val);
        }else if(queue.peek()<val){
            queue.poll();
            queue.add(val);
        }
        return queue.peek();
    } 

}

```