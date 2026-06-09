### 解题思路
	c++小白，刚接触动态规划。
	申请一个M*N的二维数组，为了方便我就用vector代替了，数组的含义是从当前位置到终点一共有几种走法。
### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
	for(int i=0;i<m;i++)
	{
		vector<int> tmp;
		for(int j=0;j<n;j++) tmp.push_back(0);
		dp.push_back(tmp);
	}
	for(int i=m-1;i>=0;i--)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(i==m-1||j==n-1)dp[i][j]=1;
			else dp[i][j]=dp[i+1][j]+dp[i][j+1];
			//cout<<"i,j:"<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	return dp[0][0];
    }
};
```