直接用java自带的优先队来实现。

```
class KthLargest {
    
    final PriorityQueue<Integer> minHeap;
    
    final int k;

    public KthLargest(int k, int[] nums) {
        
        this.k = k;
        this.minHeap = new PriorityQueue(k);
        
        for (int i = 0; i < nums.length; i++) {
            add(nums[i]);
        }
        
    }
    
    public int add(int val) {
        
        if (minHeap.size() < k) {
            minHeap.offer(val);
        } else if (minHeap.peek() < val){
            minHeap.poll();
            minHeap.offer(val);
        }
        
        return minHeap.peek();
        
    }
}
```


