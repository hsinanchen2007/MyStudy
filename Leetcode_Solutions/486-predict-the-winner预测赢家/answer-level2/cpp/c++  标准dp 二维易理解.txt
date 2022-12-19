```
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
	int n = nums.size();
    if(n%2==0)return true;//偶数个数字先手必胜
	//dp[i][j]代表在i,j范围内，先手比后手拿到最好的多多少。
    int dp[n+1][n+1];
    //由于dp[i][j]状态依赖dp[i+1][j]和dp[i][j-1],所以需要倒着遍历或者斜着遍历
	for (int i = 0; i < n; ++i) dp[i][i] = nums[i];//初始化，代表只有一个数时，等于这个数
	for (int i=n-1;i>=0;i--) //倒着遍历
    {
		for (int j=i+1;j<n;j++) 
        {
			//当先手拿num[i](左侧),后手拿的最好值为dp[i+1][j]
			//当先手拿num[j](右侧),后手拿的最好值为dp[i][j-1]
			dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
		}
	}
	return dp[0][n-1] >= 0;
    }
};

```
