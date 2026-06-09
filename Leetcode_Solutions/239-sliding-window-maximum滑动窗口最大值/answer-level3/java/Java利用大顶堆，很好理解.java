虽然效率很低，但真的很好理解
```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
      if(nums==null || nums.length<1) return new int[]{};
      PriorityQueue<Integer> queue = new PriorityQueue<Integer>((a,b)->b-a);
      int[] res = new int[nums.length-k+1];
      int m=0;
      for(int i=0;i<nums.length;i++){
        queue.add(nums[i]);
        if(queue.size()==k){
          queue=new PriorityQueue<Integer>((a,b)->b-a);
          for(int j=i;j>i-k;j--) queue.add(nums[j]);
          res[m++]=queue.poll();
        }
      }
      return res;
    }
}
```
