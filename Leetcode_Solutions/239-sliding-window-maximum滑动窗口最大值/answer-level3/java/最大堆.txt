
```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length==0) return new int[]{};
        PriorityQueue pq = new PriorityQueue<Integer>(k,new Comparator<Integer>(){
            @Override
            public int compare(Integer i1, Integer i2) {
                return i2-i1;
            }
        });
        
        int[] res = new int[nums.length-k+1];
        
        int p = 0;
        for (int i=0; i<k; i++) {
            pq.offer(nums[i]);
        }
        
        for (int j=k; j<nums.length; j++) {
            res[p] = (int)pq.peek();
            p++;
            pq.remove(nums[j-k]);
            pq.offer(nums[j]);
        }
        res[p] = (int)pq.poll();
        return res;
    }
}
```