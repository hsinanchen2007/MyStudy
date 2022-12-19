具体的注释在代码里；
预处理区间最大值也可以用ST表，但没什么必要，也快不了多少；
```
int max(int a,int b){
	return a<b?b:a;
}
int min(int a,int b){
	return a>b?b:a;
}
int minDifficulty(int* aa, int n, int d){
	int a[305]={0};
	for(int i=n;i>=1;i--){
		a[i]=aa[i-1];
	}//个人习惯用1~n的下标，不要介意
	int smax[305][305]={0};
	//smax[i][j]表示i到j这个区间的最大值
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			smax[i][j]=max(a[j],smax[i][j-1]);
		}
	}
	if(n<d){
		return -1;
	}
	int dp[12][305];//dp[i][j]表示考虑前i天，前i天恰好做完了前j件任务，所对应的最小难度和
	memset(dp,0x3f3f3f3f,sizeof(dp));
	//初始化为正无穷，方便下面写min
	dp[0][0]=0;
	for(int i=1;i<=d;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=j;k++){
				dp[i][j] = min( dp[i][j] , dp[i-1][j-k]+smax[j-k+1][j] );
			}
		}
	}
	return dp[d][n];//本题题意有点没说清楚，就是所有工作必须都做完
}

```