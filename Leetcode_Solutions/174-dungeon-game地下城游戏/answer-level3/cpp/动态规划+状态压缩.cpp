动态规划自底向上推理。设dp[i][j]表示从位置(i,j)处开始走到公主位置，所需要的体力。
则有两种路径到达(i,j)：从(i+1,j)或者从(i,j+1)。
如果当前dungeon[i][j]魔法值大于dp[i+1][j]则(i,j)处需要0体力即可，另一个类似；
如果当前dungeon[i][j]小于零，则(i,j)处需要-dungeon[i][j]+dp[i+1][j]体力，另一个类似。
注意体力和魔法值的正负情况，可以合并为dp[i][j]=max(0,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]).
最后，要保证勇者体力始终大于0。
很容易写出下面动态规划代码：
```
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if(dungeon.size()<1 || dungeon[0].size()<1) return -1;
		int m=dungeon.size(), n=dungeon[0].size();
		vector<vector<int> > dp(m,vector<int>(n,INT_MAX));
		dp[m-1][n-1]=max(0,-dungeon[m-1][n-1]);
		for(int i=m; i--;){
			for(int j=n; j--;){
				if(i==m-1 && j==n-1) continue;
				int right=j+1<n?dp[i][j+1]:INT_MAX;
				int down=i+1<m?dp[i+1][j]:INT_MAX;
				dp[i][j]=max(0,min(right,down)-dungeon[i][j]);
			}
		}
		return dp[0][0]+1;
	}
};
```
注意上面两层for循环内部，down需要的状态仅与上一层循环有关，可以进行行状态压缩，如下：
```
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if(dungeon.size()<1 || dungeon[0].size()<1) return -1;
		int m=dungeon.size(), n=dungeon[0].size();
		vector<int> dp(n,INT_MAX);
		dp[n-1]=max(0,-dungeon[m-1][n-1]);
		for(int i=m; i--;){
			for(int j=n; j--;){
				if(i==m-1 && j==n-1) continue;
				int right=j+1<n?dp[j+1]:INT_MAX;
				dp[j]=max(0,min(right,dp[j])-dungeon[i][j]);
			}
		}
		return dp[0]+1;
	}
};
```

