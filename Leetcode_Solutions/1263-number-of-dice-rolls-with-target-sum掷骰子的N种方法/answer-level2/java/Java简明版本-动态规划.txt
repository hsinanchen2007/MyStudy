# 思路讲解：
状态转移方程为：`a[i][k]=(a[i][k]+a[i-1][k-j])`，`a[i][k]`表示i个骰子共计k点。
`a[i-1][k-j]`即为上一个状态，j从1~f取值。累加后即为结果。
由于`a[i][k]`中k代表当前状态的总点数，其最小值为j，最大值为target。
由以上分析，得下方代码。
```
class Solution
{
    public int numRollsToTarget(int d,int f,int target)
    {
        int a[][]=new int[35][1050],i,j,k;
        a[0][0]=1;
        for(i=1;i<=d;i++)
            for(j=1;j<=f;j++)
                for(k=j;k<=target;k++)
                    a[i][k]=(a[i][k]+a[i-1][k-j])%1000000007;
        return a[d][target];
    }
}

```
# 关于为什么每一步都要取模，而不是最后再取模：
   因为无论是在每个中间过程中取模，和最后统一取模，本质上都是去掉整数个mod数，所以可能中间分10次mod掉了20个mod，和最后统一mod掉20个数是一样的。并且如果最后mod很可能结果已经爆了int，因此每一步取模是最稳妥的，这可以确保结果始终在合理的范围内。
