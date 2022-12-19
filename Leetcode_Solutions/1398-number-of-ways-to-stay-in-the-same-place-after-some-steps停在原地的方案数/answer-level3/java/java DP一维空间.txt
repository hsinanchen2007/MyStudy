dp存着到达当前点的可能性数量
temp存着上一步step的dp数组的值（方便本次step的计算）
并且由于把step放到循环里，不需要开二维数组，节省了空间。
注意dp数组要取steps与arrLen的最小值，不然最后那个样例可能会过不去。
```
class Solution {
    public int numWays(int steps, int arrLen) {
        //每次循环step，当前点的可能性都是由当前点的值加上前后两个点的值得到的
        if(arrLen==0&&steps!=0){
            return 1;
        }
        if(arrLen==0&&steps==0){
            return 1;
        }
        if(steps==0)
            return 1;
        if(steps==1){
            return 1;
        }
        if(arrLen==1){
            return 1;
        }
        int mod=1000000007;
        int max=Math.min(arrLen,steps);
        int dp[]=new int[max];
        int temp[]=new int[max];//存着上个step的结果
        dp[0]=1;
        dp[1]=1;//第一步初始化坐标0和坐标1
        temp[0]=dp[0];
        temp[1]=dp[1];
        int sum=0;
        for(int i=1;i<steps;i++){
            for(int j=0;j<max;j++){
                // if(j==0){
                //     dp[j]=(temp[j]+temp[j+1])%mod;
                // }
                // else if(j==arrLen-1){
                //     dp[j]=(temp[j]+temp[j-1])%mod;
                // }
                // else{
                //      dp[j]=(temp[j]+temp[j-1]+temp[j+1])%mod;
                // }
                // dp[j]%=mod;
                dp[j]=temp[j];
                dp[j]%=mod;
                if (j != 0)
                    dp[j] += temp[j-1];
                dp[j]%=mod;
                if (j != max-1)
                    dp[j] += temp[j+1];
                dp[j]%=mod;
                dp[j]%=mod;
            }
            for(int j=0;j<max;j++){
                temp[j]=dp[j];
                // dp[j]=0;
            }
        }
        return dp[0]%mod;
    }
}
```
