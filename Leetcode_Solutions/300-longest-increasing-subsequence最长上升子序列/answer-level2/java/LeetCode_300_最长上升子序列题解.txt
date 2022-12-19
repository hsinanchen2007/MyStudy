### 解题思路

- lengthOfLIS 动态规划 + 二分查找 O(nlogn)
- lengthOfLISNew 动态规划 O(n*n)

### 代码

```java
class Solution {

    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0) return 0;

        List<Integer> dp = new ArrayList<>(); // 存储数组中较小的值

        dp.add(nums[0]);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > dp.get(dp.size() - 1)) {
                dp.add(nums[i]);
            } else {
                // 二分查找dp中按照升序排列的nums[i]应该放置的位子
                int l = 0;
                int r = dp.size() - 1;

                while (l < r) {
                    int mid = (l + r) / 2;
                    if (dp.get(mid) < nums[i]) l = mid + 1;
                    else r = mid;
                }

                dp.set(l, nums[i]);
            }
        }

        return dp.size();
    }

    public int lengthOfLISNew(int[] nums) {
        if (nums.length == 0) return 0;

        int maxLen = 1;

        int[] dp = new int[nums.length];

        dp[dp.length - 1] = 1;

        for (int i = nums.length - 2; i >= 0; i--) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] < nums[j] && dp[i] < (dp[j] + 1)) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] == 0) {
                dp[i] = 1;
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
            }
        }

        return maxLen;
    }
}
```