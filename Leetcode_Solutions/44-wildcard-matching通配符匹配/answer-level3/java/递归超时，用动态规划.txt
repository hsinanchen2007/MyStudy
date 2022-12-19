### 解题思路
一开始用递归，会超时
一样的，递归思路跟dp思路一样，
主要是对？跟* 进行判断
？当做命中匹配来操作，s,跟p相同时，或者p为？时，下一步
*：要么匹配空串，即当前P不要了，下一步
    要么匹配1到N此，那么1到N在每一次的迭代中可以看成匹配一次，因为由下一次的0/1来选择其是1/2
那么就是dp[i][j]=dp[i][j-1] || dp[i-1][j]
            //\*匹配空串，并且\*不要了   //\*命中了1一次，那么他的结果跟上一个i的结果相同，j不变。
### 代码

```java
class Solution{
    public boolean isMatch(String s, String p) {

        int m=s.length();
        int n=p.length();
        boolean[][] dp=new boolean[m+1][n+1];

        dp[0][0]=true;

        for(int i=1;i<=n;i++)
            dp[0][i]=dp[0][i-1] && p.charAt(i-1)=='*';

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s.charAt(i-1)==p.charAt(j-1) || p.charAt(j-1)=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                if(p.charAt(j-1)=='*')
                    dp[i][j]=dp[i][j-1] || dp[i-1][j];
            }
        }
        return dp[m][n];

    }
}

```