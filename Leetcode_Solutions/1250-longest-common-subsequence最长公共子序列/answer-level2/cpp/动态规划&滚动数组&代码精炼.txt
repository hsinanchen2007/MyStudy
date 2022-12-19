1.dp方程：	dp[i][j]=dp[i-1][j-1]+1; //text1[i-1]==text2[j-1]
				dp[i][j]=max(dp[i][j],dp[i][j-1]); //text1[i-1]!=text2[j-1]
2.在利用二维dp数组存储结果时，需要用到dp[i-1][j-1] (左上方),dp[i-1][j] (上边),dp[i][j-1] (左边)。
3.优化为滚动数组存储结果时，由于在从左到右计算dp[j] (dp[i][j]) 的时候dp[j-1] (dp[i-1][j-1]) 已被更新为dp[j-1]（dp[i][j-1]），所以只需要提前定义一个变量last去存储二维dp数组左上方的值dp[i-1][j-1],即未被更新前的dp[j-1];
注意：计算每一行的第一个元素时候，last需要初始化为0。
```
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.size(),l2=text2.size();
	int dp[l2+1],last=0,temp;
	fill(dp,dp+l2+1,0);
        for(int i=1;i<=l1;++i,last=0){
		for(int j=1;j<=l2;++j){
            	   temp=dp[j];
		   if(text1[i-1]==text2[j-1])	dp[j]=last+1; 
		   else	 dp[j]=max(dp[j],dp[j-1]);
        	   last=temp;
		}
        }
	return dp[l2];
    }
};
```

