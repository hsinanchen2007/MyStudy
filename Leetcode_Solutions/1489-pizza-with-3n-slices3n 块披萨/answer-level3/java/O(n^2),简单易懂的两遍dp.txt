### 解题思路
思路很简单,就是一个状态转移方程的事儿
**dp[i][j] = Math.max(dp[i - 2][j - 1] + slices[i], dp[i - 1][j]);**
两遍dp是为了排除首尾均被选择的情况

### 代码

![image.png](https://pic.leetcode-cn.com/c3609a5487056e81064a6b38628540bdf9562954c9181203f41c5b52b50fa795-image.png)

```java
class Solution {
   public int maxSizeSlices(int[] slices) {

		int len = slices.length;
		int res=0;
		int[][] dp = new int[len+1][len / 3 + 1];
		dp[0][1] = slices[0];
		dp[1][1] = Math.max(slices[0], slices[1]);
		for (int i = 2; i < len-1; i++) {

			for (int j = 1; j <= len / 3; j++) {
				if(j>i/2+1){
					break;
				}
				dp[i][j] = Math.max(dp[i - 2][j - 1] + slices[i], dp[i - 1][j]);
			}

		}

		res=dp[len - 2][len / 3];//不包括最后一个披萨的情况
		dp = new int[len+1][len / 3 + 1];
		dp[0][1] =0;//把第一块披萨设置为0,确保它不会被挑选
		dp[1][1] =slices[1];
		for (int i = 2; i < len; i++) {

			for (int j = 1; j <= len / 3; j++) {
				if(j>i/2+1){
					break;
				}
				dp[i][j] = Math.max(dp[i - 2][j - 1] + slices[i], dp[i - 1][j]);
			}

		}
		return Math.max(dp[len - 1][len / 3],res);//两种情况取最大,就是最终结果
	}
}
```