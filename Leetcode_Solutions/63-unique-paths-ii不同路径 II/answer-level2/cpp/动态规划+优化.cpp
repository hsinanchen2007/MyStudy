### 解题思路
此处撰写解题思路
解题思路详见代码块

### 代码

```cpp
//普通动态规划
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        if(m==0) return 0;
        int n=obstacleGrid[0].size();
        long dp[m][n];
        int temp=0;
        //这里的两个是为了把边缘的路径搞定，避免动态规划时出错
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]!=1&&temp!=1){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=0;
                temp=1;
            }
        }
        temp=0;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]!=1&&temp!=1){
                dp[i][0]=1;
            }
            else{
                dp[i][0]=0;
                temp=1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(obstacleGrid[i-1][j]==1&&obstacleGrid[i][j-1]==1){//i-1，j-1，这里就用到了上面两个循环的好处
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];//不管有没有路径，相加就对了。
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//动态规划优化
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m=obstacleGrid.size();
		int n=obstacleGrid[0].size();
		
		vector<long> dp(n, 0);
        dp[0]=1;
		for(int i=0;i<m;i++){
			if(obstacleGrid[i][0])
				dp[0]=0;
			for(int j=1;j<n;j++){
				if(obstacleGrid[i][j])
					dp[j]=0;
				else
					dp[j]+=dp[j-1];/*这里是理解重点。想想上面的普通动态规划，这一步是把它的上面和左边相加，那这里的dp[j]就是上面了（为什么呢？想明白那就成功80%了),dp[j-1]就是左边了。*/
			}	
		}
        return dp[n-1];
	}
};
```