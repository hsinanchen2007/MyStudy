```
class Solution {
    /**
     * 桶排序
     * 时间复杂度O(n)
     */
    public int maximumGap(int[] nums) {

        if(nums.length < 2 || nums == null) return 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[i]);
        }
        if(max == min) return 0;

        boolean[] hasNum = new boolean[len+1];
        int[] mins = new int[len+1];
        int[] maxs = new int[len+1];
        int bid = 0;
        //将1.最大值 2.最小值 3.是否有值 等信息放入桶中
        for (int i = 0; i < len; i++) {
            bid = bucket(nums[i], len, min,max);
            maxs[bid] = hasNum[bid] ? Math.max(maxs[bid],nums[i]) : nums[i];
            mins[bid] = hasNum[bid] ? Math.min(mins[bid],nums[i]) : nums[i];
            hasNum[bid] = true;
        }

        //找到最大间隔
        int last = maxs[0];
        int maxGap = Integer.MIN_VALUE;
        for (int i = 1; i <= len; i++) {
            if(hasNum[i]){
                maxGap = Math.max(maxGap, mins[i] -last);
                last = maxs[i];
            }

        }

        return maxGap;
    }

    //计算出应该去几号桶，可以理解为在len中的占比
    public static int bucket(long num, long len, long min, long max) {

        return (int) ((num - min) * len / (max - min));
    }
}
```
