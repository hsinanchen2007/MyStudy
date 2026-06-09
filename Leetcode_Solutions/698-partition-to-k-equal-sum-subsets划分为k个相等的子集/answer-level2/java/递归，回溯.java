### 解题思路
题目的意思应该是分完之后，nums里面有的数没有分到任何一个子集中，也算满足条件的。
之前想错了，以为每个数都要在其中一个子集，分完后不能有未分配的数。
使用一个boolean[]数组记录数是否用过，回溯的时候，如果用过的数不能满足条件，那么再将其设置为未用。

### 代码

```java
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum=0, max=0;
        for (int i=0; i<nums.length; i++) {
            sum += nums[i];
            max = Math.max(max, nums[i]);
        }
        if (sum%k != 0 && max > sum/k) {
            return false;
        }
        boolean[] used = new boolean[nums.length];
        return getSearch(nums, k, sum/k, 0, 0, used);
    }
    private boolean getSearch(int[] nums, int k, int target, int cur, int start, boolean[] used) {
        if (k == 0) {
            return true;
        }
        if (cur == target) {
            return getSearch(nums, k-1, target, 0, 0, used);
        }
        for (int i=start; i<nums.length; i++) {
            if (!used[i] && cur+nums[i] <= target) {
                used[i] = true;
                if (getSearch(nums, k, target, cur+nums[i], i+1, used)) {
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
}
```