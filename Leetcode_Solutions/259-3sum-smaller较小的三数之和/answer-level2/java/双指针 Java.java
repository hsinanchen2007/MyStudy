```
class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = 0;
        for(int i=0; i<nums.length-2; ++i){
            int newtar = target - nums[i];
            int L = i+1, R = nums.length-1;
            while(L < R){
                if(nums[L] + nums[R] < newtar){
                    ans+=(R-L);
                    L++;
                }else{
                    R--;
                }
            }
        }
        return ans;
    }
}

```
