### 解题思路
反向看问题。
### 代码

```java
class Solution {
    public int numWays(int n) {
        if(n==1||n==2)return n;
        if(n>2){
             int[] dp=new int[n+1];
             dp[0]=1;
             dp[1]=2;
             int temp=0;
             for(int i=2;i<n;i++){
                dp[i-1]%=1000000007;
                dp[i-2]%=1000000007;
                dp[i]=dp[i-1]+dp[i-2];
                temp=dp[i]%1000000007;
            }
            return temp;
        }
        return 1;
    }
}
```