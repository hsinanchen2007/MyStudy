# 利用PriorityQueue类，默认为小顶堆，解决topK问题。
即将n个数，设置一个k大小的小顶堆，向其中加入元素，保持堆大小不变的情况下，最终堆中保存的就是n个数中前k大的数，且堆顶刚好为第k大的数。
每次新增一个数据时，判断是否比堆顶元素大，如果是，则堆顶元素将成为第k+1大的数，需要出堆，让新元素入堆，重新调整堆后，堆顶元素为新的第k大的数。
注意：PriorityQueue类的add方法加入元素会产生自动扩容，导致堆大小变化，因此在使用时需要判断堆的大小。若未超过大小则加入，反之进行堆顶元素比较和调整。
```
class KthLargest {
    private PriorityQueue<Integer> minHeap; 
    private int length; //记录小顶堆的大小
    
    public KthLargest(int k, int[] nums) {
        length = k;
        minHeap = new PriorityQueue<>(k);   //设置k大小的小顶堆
        for(int n : nums){
           add(n);  //调用该类的add方法，不能调用PriorityQueue的add方法，否则会自动扩容，堆的大小改变。
        }
    }
    
    public int add(int val) {
        if (minHeap.size() < length) {  //用于添加数据
            minHeap.add(val);
        } else if (val > minHeap.peek()) {  //如果当前堆顶数据小于新增数据，则堆顶数据不再是第k大的数，出堆并加入新元素进行重新排序
            minHeap.poll();
            minHeap.add(val);
        }
        return minHeap.peek();  
    }
}
```
