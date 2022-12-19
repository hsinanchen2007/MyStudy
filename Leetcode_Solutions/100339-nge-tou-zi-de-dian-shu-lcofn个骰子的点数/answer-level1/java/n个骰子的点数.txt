### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double[] twoSum(int n) {
        int [][] dp=new int[n+1][6*n+1];
        //边界条件
        for(int s=1;s<=6;s++)
        {
            dp[1][s]=1;
        }
        //进行迭代
        for(int i=2;i<=n;i++)
        {
            for(int s=i;s<=6*i;s++)
                //最少是i个
                {
                    for(int d=1;d<=6;d++)
                    {
                        if(s-d<i-1)  //实际不会有
                            break;
                        dp[i][s]+=dp[i-1][s-d];
                    }
                }
        }
        double total=Math.pow((double)6,(double)n);
        double [] ans=new double[5*n+1];
        for(int i=n;i<=6*n;i++)
            ans[i-n]=((double)dp[n][i])/total;
        return ans;
    }
}
```