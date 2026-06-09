class Solution {
   
    public int movesToMakeZigzag(int[] nums) {
        int size = nums.length;
        if (size <= 2) return 0;
        int m = 0;  // 0> 1 < 2
        int n = 0;  // 0< 1 > 2 < 3
        int i;
        for (i= 1; i< size; i = i + 2) {
            m += calNbr(nums, size, i);
        }

        for (i= 0; i< size; i = i + 2) {
            n += calNbr(nums, size, i);
        }

        return m < n  ? m : n;
    }
    
    int calNbr(int[] nums, int size, int i)
    {   
        int t;
        int step = 0;
        if (i >= 1) {
            t = nums[i] - nums[i - 1];
            if (t >= 0) step = t + 1;
        }

        if ((i + 1) < size) {
            t = nums[i] - nums[i + 1];
            if (t >= 0) step = (step < t + 1) ? t + 1 : step;
        }
        return step;
    }

}