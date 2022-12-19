class Solution {
    public int massage(int[] nums) {
        if(nums.length == 0)
            return 0;
        int[] opt = new int[nums.length];
        opt[0] =nums[0];
        if(nums.length >= 2)
            opt[1] = Math.max(nums[0], nums[1]);
        for(int i = 2; i < nums.length; i++){
            int a = opt[i-2] + nums[i];
            int b = opt[i-1];
            opt[i] = Math.max(a, b);
        }
        return opt[opt.length-1];
    }
}