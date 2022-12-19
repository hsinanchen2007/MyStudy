### 解题思路
1. 搜索加剪枝，参考大神的题解。
2. 01背包解法，递归或动态规划。

### 代码

```java
class Solution {
    public boolean canPartition(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum % 2 == 1) return false;
        int halfSum = sum / 2;
        return dp(nums, nums.length-1, halfSum, halfSum);
    }

    private boolean dp(int[] nums, int idx, int left, int right){
        if(left == 0 || right == 0) return true;
        if(left < 0 || right < 0) return false;
        return dp(nums, idx-1, left-nums[idx], right) || dp(nums, idx-1, left, right-nums[idx]);
    }
}
```