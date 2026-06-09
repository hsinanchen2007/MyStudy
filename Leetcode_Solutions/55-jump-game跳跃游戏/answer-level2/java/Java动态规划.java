```
class Solution {
    public boolean canJump(int[] nums) {
        int maxto  = nums[0], start = 0;
         return helper(0, nums[0], nums);
    }
    public boolean helper(int start, int maxto,int[] nums) {
        int tmpmaxto = maxto;
        int premaxto = maxto;
        for ( int i = start; i <= maxto; i++){
            if(i + nums[i] >= nums.length - 1)
                return true;
            if(i + nums[i] > maxto) {
                maxto = Math.max(i + nums[i],tmpmaxto);
                start = maxto - nums[i];
               
            }
        }
        if (maxto > nums.length -1)
            return true;
        if (maxto <= premaxto)
            return false;
        else
            return helper(premaxto, maxto, nums);
        }
    }
