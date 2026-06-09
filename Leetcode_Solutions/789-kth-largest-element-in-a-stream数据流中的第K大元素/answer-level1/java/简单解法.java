```
class KthLargest {
    //维持一个size位k的小根堆，里面存的都是到现在为止前K个最大的数
    PriorityQueue<Integer> heap;
    int k;
    public KthLargest(int k, int[] nums) {
        heap = new PriorityQueue<>(k);
        this.k = k;
        
        //把初始元素加入堆
        for(int i : nums){
            add(i);
        }
    }
    
    public int add(int val) {
        if(heap.size() == k && val > heap.peek()){
            heap.poll();
        }
        if(heap.size() < k){
            heap.add(val);
        }
        return heap.peek();
    }
}

```
