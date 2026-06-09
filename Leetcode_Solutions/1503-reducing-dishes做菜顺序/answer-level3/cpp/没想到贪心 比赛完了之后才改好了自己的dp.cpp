### 解题思路
这道题写的有点难受 又是打完比赛之后马上改出来的题目
去年的两场区域赛都是因为这样和银牌失之交臂 打了三年的铜牌
归结原因还是平时练得少 比赛的时候说得上思路 但写起来磕磕绊绊
自己以后 少摸鱼 多学习 争取2021 考上研究生吧

dp[目前正在上的菜][上了n道菜] = 上了n道菜满意度的最大值
### 代码

```cpp
class Solution {
public:
	int dp[666][666] = { 0 };
	int kkk[666];
    int kk[666];
	int ans = 0;

	void init(void)
	{
		for (int i = 0; i < 666; i++)for (int j = 1; j < 666; j++)dp[i][j] = -100000000;
		for (int i = 0; i < 666; i++)kkk[i] = -100000000;//最小值记得尽量小一些 不能只写-10000
        for (int i = 0; i < 666; i++)kk[i] = -100000000;
	}
	int maxSatisfaction(vector<int>& satisfaction) {
		int ans = 0;
		init();
		sort(satisfaction.begin(), satisfaction.end());
		dp[0][0] = 0;
		dp[0][1] = satisfaction[0];
		kkk[0] = 0;
		kkk[1] = satisfaction[0];
        kk[0] = 0;
		kk[1] = satisfaction[0];

		for (int i = 1; i < satisfaction.size(); i++)
		{
            for (int j = 1; j <= i; j++)kkk[j] = kk[j];//更新数组
			for (int j = 1; j <= i + 1; j++)
			{
				//for (int k = 0; k < i; k++)第一次写超时了 
					//dp[i][j] = max(dp[i][j], dp[k][j - 1] + satisfaction[i] * j);
				dp[i][j] = max(dp[i][j], kkk[j - 1] + satisfaction[i] * j);
				ans = max(ans, dp[i][j]);
				kk[j] = max(dp[i][j], kk[j]);//后来改的时候 发现需要用两数组来保存 不能一边变化一边存
			}
		}
		//for (int i = 0; i <= satisfaction.size(); i++)ans = max(dp[satisfaction.size() - 1][i], ans);
		return ans;
	}
}s;
```