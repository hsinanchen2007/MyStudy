### 解题思路
两种方式，一种自底向上，一种自顶向下，都是O(n),自底向上较为容易，就是dp方法。
自顶向下每次用一个变量存下dp[j-1]的值，然后注意边界的值，就和自底向上差不多了。

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) 
    {//自顶向下
        if(triangle==null||triangle.size()==0)
        {
            return 0;
        }
        int n=triangle.size();
        int dp[]=new int[n+2];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                {
                    dp[n]=dp[j];
                    dp[j]=dp[j]+triangle.get(i).get(j);
                    
                }
                else if(i==j)
                {
                    dp[j]=dp[n]+triangle.get(i).get(j);
                }
                else
                {
                    int tmp=dp[n];
                    dp[n]=dp[j];
                    dp[j]=Math.min(dp[j],tmp)+triangle.get(i).get(j);
                }
            }
        }
        int minsum=dp[0];
        for(int i=0;i<n;i++)
        {
            minsum=Math.min(minsum,dp[i]);
        }
        return minsum;
    }
}

    // //自底向上
    //     if(triangle==null||triangle.size()==0)
    //         return 0;
    //     int n= triangle.size();
    //     int dp[]=new int[n+1];
    //     int min=triangle.get(0).get(0);
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         for(int j=0;j<=i;j++)
    //         {
    //             dp[j]=Math.min(dp[j],dp[j+1])+triangle.get(i).get(j);
    //         }
    //     }
    //     return dp[0];
    // 

```