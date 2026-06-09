### 解题思路
dp, dp[i] = 从0-i进行遍历，若nums[j]<nums[i],则尝试更新dp[i];
完成dp数组后，遍历得到最大值

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int len = nums.length;
		if(len < 2)return len;
        int[] dp = new int[len];
        Arrays.fill(dp, 1);
        for(int i = 1; i < len; i++) {
        	
        	for(int j = 0; j < i; j++) {
        		if(nums[j] < nums[i]) {
        			dp[i] = Math.max(dp[j] + 1, dp[i]);
        		}
        	}
        }
        int res = dp[0];
        for(int i = 1; i < len; i++) {
        	if(dp[i] > res)res = dp[i];
        }
        return res;
    }
}
```