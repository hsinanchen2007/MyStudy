首先给定一个数组我遍历一遍可以求出
这个数组的最小值  min
这个数组的最大值 max 
并且在遍历的时候我将数组放入set中去

之后只需要判断如果这个数组的最小值 min 大于 1 那就 可以直接 reutrn 1了
否则
缺失的第一个正整数一定是出现在 1 到 max+1之间的

class Solution {
    public int firstMissingPositive(int[] nums) {
        if (nums.length == 0) {
            return 1;
        }
        int min = nums[0];
        int max = nums[0];
        Set<Integer> set = new HashSet();
        for (int num : nums) {
            set.add(num);
            min = Math.min(min,num);
            max = Math.max(max,num);
        }
        max = max < 1 ? 1 : max;
        if (min > 1) {
            return 1;
        } else {
            for (int i=1;i<=max;i++) {
                if (!set.contains(i)) {
                    return i;
                }
            }
            return max+1;
        }
    }
}