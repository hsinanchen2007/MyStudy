
```java
class Solution {
    ArrayDeque<Integer> queue = new ArrayDeque<>();
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums==null || nums.length==0 ||k==1) return nums;
        int[] res = new int[nums.length-k+1];
        for (int l = 0; l <k; l++) {
            clean(nums, l, k);
            queue.addLast(l);
        }
        res[0]=nums[queue.getFirst()];
        for (int i = k; i < nums.length; i++) {
            clean(nums, i, k);
            queue.add(i);
            res[i-k+1] = nums[queue.getFirst()];
        }
        return res;
    }
    public void clean(int[] nums,int i, int k){
        while(!queue.isEmpty() &&queue.getFirst()==i-k) queue.removeFirst();
        while(!queue.isEmpty() &&nums[i]>nums[queue.getLast()]) queue.removeLast();
    }

    
}
```