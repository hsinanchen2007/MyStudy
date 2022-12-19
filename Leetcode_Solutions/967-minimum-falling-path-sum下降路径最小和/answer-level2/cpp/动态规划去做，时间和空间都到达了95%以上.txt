数组大小为size x size
假设dp数组为size x size
    那么就是结果为dp[row][column]=min(dp[row-1][column-1],dp[row-1][column],dp[row-1][column+1])+A[row][column];
而本方法是为了减小空间的消耗，将N^2的空间缩小到了2xN的大小。
这里使用了row%2的方法去确定本行和上一行；
最终是到达了最后一行所有节点各自的最小值
具体代码如下显示
```
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int size=A.size();
        if(size<2)return A[0][0];
        vector<vector<int>> dp(2,vector<int>(size,0));
        int s=0;
        for(int i:A[0]){
            dp[0][s++]=i;
        }
        int f1,f2;
        for(int j=1;j<size;j++){
            f1=j%2;
            f2=1-f1;
            dp[f1][0]=min(dp[f2][0],dp[f2][1])+A[j][0];
            for(int i=1;i<size-1;i++){
                dp[f1][i]=min(dp[f2][i],min(dp[f2][i-1],dp[f2][i+1]))+A[j][i];
            }
            dp[f1][size-1]=min(dp[f2][size-1],dp[f2][size-2])+A[j][size-1];
        }
        int res=dp[f1][0];
        for(int i:dp[f1]){
            res=min(res,i);
        }
        return res;
    }
};
```
