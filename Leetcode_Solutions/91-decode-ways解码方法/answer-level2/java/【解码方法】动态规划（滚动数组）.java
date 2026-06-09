### 解题思路
入门级dp题，设`dp[i]`为前`i`个字母的解码数，则有：
$
dp[i]  \ += \left\{
\begin{aligned}
dp[i - 1]，&  {1≤ s[i] ≤ 9} \\
dp[i - 2]，&  {10 ≤ concat(s[i - 1], s[i]) ≤ 26}  \\
\end{aligned}
\right.
$  

- `1≤ s[i] ≤ 9`： 最后一个字母可以解码为`1~9`的数字
- `10 ≤ concat(s[i - 1], s[i]) ≤ 26`：最后两个字母可以解码为`10~26`的数字

由状态转移方程可以看出，每次状态转移的时候只需要用到前两项的值，所以可以考虑用长度为`3`的滚动数组。

### 代码

```java
class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        
        // 特判一下空字符串
        if (n == 0) {
            return 0;
        }

        // 滚动dp数组
        int[] dp = new int[3];

        dp[0] = dp[1] = 0;
        dp[2] = 1;

        int doubleBitNum = 0, singleBitNum;
        for (int i = 0; i < n; i++) {
            singleBitNum = s.charAt(i) - '0';
            dp[i % 3] = 0;
            if (singleBitNum != 0) {
                dp[i % 3] += dp[(i + 2) % 3];  
            }
            doubleBitNum = doubleBitNum * 10 + singleBitNum;
            if (10 <= doubleBitNum && doubleBitNum <= 26) {
                dp[i % 3] += dp[(i + 1) % 3];
            }
            doubleBitNum = singleBitNum;
        }
        return dp[(n + 2) % 3];
    }
}
```