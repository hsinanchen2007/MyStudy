### 解题思路
两个可用于动态规划的递增数据：工作数和天数。
构造二维数组dp[i][j]，表示前i个工作j天完成需要的最小难度，然后按天数和工作数递推即可。
核心代码：
```
dp[j][i]=min(dp[j][i],dp[k][i-1]+maxHard(k+1,j,jobDifficulty));
```
### 代码

```c
int hard[300][300];
int max(int x,int y){
    return x>y?x:y;
}
int min(int x,int y){
    return x<y?x:y;
}
int maxHard(int i,int j,int* a){
    if(hard[i][j]) return hard[i][j];
    int k,maxn=0;
    for(k=i;k<=j;k++){
        maxn=max(maxn,a[k]);
    }
    return maxn;
}
int minDifficulty(int* jobDifficulty, int jobDifficultySize, int d){
    if(jobDifficultySize<d) return -1;
    int dp[300][11];
    int i,j;
    for(i=1;i<=d;i++)
        for(j=0;j<jobDifficultySize;j++){
            if(i==1){
                if(j==0) dp[0][1]=jobDifficulty[0];
                else dp[j][1]=max(jobDifficulty[j],dp[j-1][1]);
            }
            else{
                int k;
                for(k=i-2;k<j;k++){
                    if(k==i-2) dp[j][i]=dp[k][i-1]+maxHard(k+1,j,jobDifficulty);
                    else dp[j][i]=min(dp[j][i],dp[k][i-1]+maxHard(k+1,j,jobDifficulty));
                }
            }
        }
    return dp[jobDifficultySize-1][d];
}
```