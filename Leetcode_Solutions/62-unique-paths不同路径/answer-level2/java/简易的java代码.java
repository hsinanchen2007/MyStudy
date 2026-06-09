### 代码

```java
public class Solution {
	public int uniquePaths(int m,int n){
		/*
		 * 划重点：机器人每次只能向下或者向右移动一步
		 * 用(i,j)表示当前所处位置，则有状态转移方程：
		 * dp[i][j] = dp[i-1][j] + dp[i][j-1]
		 */
		int[][] dp = new int[m][n];
		// 初始化第一行与第一列
		for(int i=0;i<m;i++){
			dp[i][0] = 1;
		}
		for(int j=0;j<n;j++){
			dp[0][j] = 1;
		}
		// 进行动态规划
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
		
		/*
		 * 这样是对的，但是会超时
		if(m == 1 && n == 1){
			return 1;
		}else if(m<1 || n<1){
			return 0;
		}
		return uniquePaths(m-1,n)+uniquePaths(m,n-1);
		*/
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/d8558d2c0aa5c2945217cc9ac090eb2d6bfa3dc032939d1c68fae86bf7609835-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/ae961e8f05ca61de8cc8972db5cc8062519131d7bb6a1cfdee05e289b92b7ca9-wechat.png)

