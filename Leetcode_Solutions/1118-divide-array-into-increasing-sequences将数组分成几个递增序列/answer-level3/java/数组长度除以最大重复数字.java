

class Solution {
    public boolean canDivideIntoSubsequences(int[] nums, int K){
        int step = 0, max = 0;
        for(int i = 1; i < nums.length;i++){
            if(nums[i] == nums[i -1]){
                step ++;
                if(step > max){
                    max = step;
                }
            } else {
                step = 0;
            }
        }
        int seq = nums.length / max;
        return seq >= K;
    }
}
```
