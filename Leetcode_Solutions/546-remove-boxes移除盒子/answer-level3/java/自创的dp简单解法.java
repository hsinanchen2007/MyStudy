### 解题思路
dp[i][j][k]代表i到j区间,最后一步移除k个nums[j]所得到的的值,比如
"121212"=>dp[0][5][1]表示合并完其他的,最后剩下一个2
        =>dp[0][5][2]表示合并完其他的,最后剩下两个2
		...


### 代码

```java
class Solution {
    public int removeBoxes(int[] nums) {
		int len = nums.length;
		if(len==0){
			return 0;
		}
		int[][][] dp = new int[len][len][len + 1];
       
		for (int j = 0; j < len; j++) {
			dp[j][j][1] = 1;
			int count = 1;
			for (int i = j - 1; i >= 0; i--) {

				count += (nums[i] == nums[j] ? 1 : 0);
				for (int temp_k = 1; temp_k <= len; temp_k++) {
					dp[i][j][1] = Math.max(dp[i][j][1], dp[i][j - 1][temp_k] + 1);
				}
				for (int k = 2; k <= count; k++) {

                    int temp_count=0;
					for (int x = j - 1; x >= i; x--) {
						if (nums[x] == nums[j]) {
                            temp_count++;
                            if(count-temp_count+1<k){
                                break;
                            }
							dp[i][j][k] = Math.max(dp[x + 1][j][1] + dp[i][x][k - 1]+2*k-2, dp[i][j][k]);
						}
					}
				}

			}

		}
		int max=0;
		for (int i = 0; i <= len; i++) {
			max = Math.max(max,dp[0][len - 1][i]);
		}
		return max;
	}
}
```