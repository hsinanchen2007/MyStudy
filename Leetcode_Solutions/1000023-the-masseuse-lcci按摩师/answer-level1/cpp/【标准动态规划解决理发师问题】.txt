### 解题思路
1,最近练习DP，没有简化
2，状态方程为dp[x][y],x表示天数，y表示此次是否接受预约
3，还需要考虑0和1的情况，好几次都栽在这里了
4，写了注释，总体思路是做过的股票买卖系列188题，进行了降维度
### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
	vector<vector<int> > dp(n, vector<int>(2, 0));
	dp[0][0] = 0;
	dp[0][1] = nums[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);//上次已经约和这次不想约
		dp[i][1] = dp[i - 1][0] + nums[i];//上次未约这次约------需要考虑三种状态
	}
	return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
```