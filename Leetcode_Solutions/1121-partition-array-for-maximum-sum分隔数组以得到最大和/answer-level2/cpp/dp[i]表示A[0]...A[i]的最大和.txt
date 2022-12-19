```
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int dp[505]={0};  //dp[i]表示A[0]...A[i]的最大和，一定要手动初始化为0
        int n=A.size(),maxtmp;
        for(int i=0;i<n;i++)
        {
            maxtmp=A[i];
            for(int len=1;len<=K && i-len+1>=0;len++) //找i前面最近的len个数字中的最大值
            {
                //A[i-len+1]...A[i]
                maxtmp=max(maxtmp,A[i-len+1]);  //随着len值的增加，每次向左扩充一位
                //i-len+1前面一位是i-len
                if(i-len>=0)
                    dp[i]=max(dp[i],dp[i-len]+maxtmp*len);
                else
                    dp[i]=max(dp[i],maxtmp*len);   //最近的len位都被替换成maxtmp的值，这样结果最大
            }
        }
        return dp[n-1];
    }
};
```
