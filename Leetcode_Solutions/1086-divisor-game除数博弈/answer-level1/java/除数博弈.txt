### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean divisorGame(int N) {
        if(N==1)
            return false;
        if(N==2)
            return true;
        boolean [] dp=new boolean [N+1];
        dp[1]=false;
        dp[2]=true;

        for(int i=3;i<=N;i++)
        {
            dp[i]=false;
            for(int j=1;j<i;j++)
            {
                if(i%j==0&&!dp[i-j])
                {
                    dp[i]=true;
                    break;
                }
            }
        }

        return dp[N];
    }
}
```