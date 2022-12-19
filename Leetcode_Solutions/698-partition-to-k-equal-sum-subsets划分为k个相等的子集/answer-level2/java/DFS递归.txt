递归放入k个集合
```
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        Integer[] newNums = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            newNums[i] = nums[i];
            sum += nums[i];
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        int[] set = new int[k]; // k哥集合
        Arrays.sort(newNums, new Comparator<Integer>() { // 从大到小选取
            public int compare(Integer i1, Integer i2) {
                return i2 - i1;
            }
        });
        return dfs(0, set, newNums, target);
    }

    // 递归放入k个集合
    public boolean dfs(int index, int[] set, Integer[] nums, int target) {
        if (index >= nums.length) {
            for (int i = 0; i < set.length; i++) {
                if (set[i] != target) {
                    return false;
                }
            }
            return true;
        }

        for (int i = 0; i < set.length; i++) {
            if (set[i] + nums[index] <= target) {
                set[i] += nums[index];
                if (dfs(index + 1, set, nums, target)) {
                    return true;
                }
                set[i] -= nums[index];
            }
        }

        return false;
    }
}
```
