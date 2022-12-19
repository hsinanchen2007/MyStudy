### 解题思路
状态转移公式
dp[i] = dp[i+1] + [i,i+1]<25?dp[i+2]

https://blog.csdn.net/sarafina527/article/details/103522295

### 代码

```java
class Solution {
    public int translateNum(int num) {
        String nstr = String.valueOf(num);
        int n = nstr.length();
        int[] dp = new int[n+1];
        dp[n] = 1;
        for (int i=n-1;i>=0;i--) {
            if (i+1<=n) {
                dp[i] += dp[i+1];
            }
            if (i+2<=n && nstr.charAt(i)!='0' && nstr.substring(i,i+2).compareTo("25")<=0 ) {
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
}
```
![image.png](https://pic.leetcode-cn.com/f21b095bd0cc095a6d5bffaf9ca417636522fe5e6f324f238eef3b9819f470ab-image.png)
