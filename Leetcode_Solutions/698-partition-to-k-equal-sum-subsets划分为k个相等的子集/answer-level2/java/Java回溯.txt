### 解题思路
普通的回溯，有一个坑是必须是从大的数开始回溯才不会超时

### 代码

```java

/**
 * Solution
 *
 * @author jianghe
 * @since 2020-04-02
 */
class Solution {
    private int[] record;

    public boolean canPartitionKSubsets(int[] nums, int k) {
        record = new int[nums.length];
        Arrays.sort(nums);
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        if (total % k != 0) {
            return false;
        }
        int target = total / k;
        int row = nums.length - 1;
        while (row >= 0 && nums[row] == target) {
            record[row] = 1;
            row--;
            k--;
        }
        int[] newNums = new int[row + 1];
        System.arraycopy(nums, 0, newNums, 0, row + 1);
        return partition(newNums, 0, target, k);
    }

    // 需要找到k个和为target的数组
    private boolean partition(int[] nums, int now, int target, int k) {
        if (k == 0) {
            return true;
        }

        if (now == 0) {
            int index = nums.length - 1;
            while (record[index] == 1) {
                index--;
            }
            record[index] = 1;
            if (partition(nums, nums[index], target, k)) {
                return true;
            }
            record[index] = 0;
            return false;
        }

        for (int i = 0; i < nums.length; i++) {
            if (record[i] == 1) {
                continue;
            }
            int temp = now + nums[i];
            if (temp > target) {
                return false;
            }
            record[i] = 1;
            if ((temp == target && partition(nums, 0, target, k - 1))
                || partition(nums, temp, target, k)) {
                return true;
            }
            record[i] = 0;
        }
        return false;
    }
}
```