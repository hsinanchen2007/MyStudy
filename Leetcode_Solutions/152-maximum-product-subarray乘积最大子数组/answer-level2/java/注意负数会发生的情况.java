class Solution {
    public int maxProduct(int[] nums) {
        if(nums.length == 0) return 0;
        int l = nums.length;
        //因为遇到负数时：
        //最大数会变最小数，最小数会变最大数，所以维护一个max和min
        //ans则一直是最优最大数
        int ans = nums[0],max = nums[0],min = nums[0];

        for(int i = 1;i < nums.length;i++) {
            if(nums[i] < 0){
                int temp = max;
                max = min;
                min = temp;
            }
            max = Math.max(max * nums[i], nums[i]);
            min = Math.min(min * nums[i], nums[i]);
            ans = Math.max(max,ans);
        }

        return ans;
    }
}