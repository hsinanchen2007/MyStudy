### 解题思路
慢慢开始欣赏算法之美

### 代码

```java
class Solution {
    int count = 0;

    public int findTargetSumWays(int[] nums, int S) {
        int sum = 0;
        dfs(nums, sum, S, 0);
        return count;
    }

    private void dfs(int[] nums, int sum, int target, int level) {
        if (level == nums.length) {
            if (sum == target) {
                count++;
            }
            return;
        }
        dfs(nums, sum + nums[level], target, level + 1);
        dfs(nums, sum - nums[level], target, level + 1);
    }
}
```