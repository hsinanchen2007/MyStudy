### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] countBits(int num) {
        int [] dp=new int[num+1];
        for(int i=0;i<=num/2;i++)
        {
            dp[i*2]=dp[i];
            if(i*2+1<=num)
                dp[i*2+1]=dp[i]+1;
        }
        return dp;
    }
}
```