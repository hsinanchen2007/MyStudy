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