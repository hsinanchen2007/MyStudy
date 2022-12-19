### 解题思路
动态规划，建立数组存储前i位的最长升序长度，遍历迭代比较，数组中的最大值即为答案。

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
    	if (nums.length<2) {
			return nums.length;
		}
    	int ans=1;
    	int[]dp=new int[nums.length];     //新建一个长度为原数组的数组用于储存前i位的最长升序列长度
    	Arrays.fill(dp, 1);     //初始值全部赋值为1
    	for (int i = 0; i < nums.length; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i]>nums[j]) {
					dp[i]=Math.max(dp[i], dp[j]+1);   //若出现更大的数，则把第j个的最长序列+1再比较
				}
			}
			ans=Math.max(dp[i],ans);      //随便取出dp数组的最大值作为答案
		}
		return ans;
    }
}
```