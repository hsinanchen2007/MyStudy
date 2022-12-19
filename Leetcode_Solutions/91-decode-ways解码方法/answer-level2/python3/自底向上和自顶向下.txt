## 思路:

动态规划

`dp[i]`到字符串第`i`位置最多解码的个数

动态方程: `dp[i] = dp[i-1] + dp[i - 2]`

注意:这里有很多要考虑的情况

例如:`101`,`100`,所以要考虑有`0`的情况,直接看代码,注释写在里面了!

再附上自顶向下的动态规划, 大家可以提供 `Java`版本吗?

## 代码:

自底向上

```python [1]
class Solution:
    def numDecodings(self, s: str) -> int:
        dp = [0] * len(s)
        # 考虑第一个字母
        if s[0] == "0":
            return 0
        else:
            dp[0] = 1
        if len(s) == 1: return dp[-1]
        # 考虑第二个字母
        if s[1] != "0":
            dp[1] += 1
        if 10 <= int(s[:2]) <= 26:
            dp[1] += 1
        for i in range(2, len(s)):
            # 当出现连续两个0
            if s[i - 1] + s[i] == "00": return 0
            # 考虑单个字母
            if s[i] != "0":
                dp[i] += dp[i - 1]
            # 考虑两个字母
            if 10 <= int(s[i - 1] + s[i]) <= 26:
                dp[i] += dp[i - 2]
        return dp[-1]
```



```java [1]
class Solution {
    public int numDecodings(String s) {
        int[] dp = new int[s.length()];
        // 考虑第一个字母
        if (s.charAt(0) == '0') return 0;
        else dp[0] = 1;

        if (s.length() == 1) return dp[dp.length - 1];

        // 考虑第二字母
        if (s.charAt(1) != '0') dp[1] += 1;
        if (10 <= Integer.parseInt(s.substring(0, 2)) && Integer.parseInt(s.substring(0, 2)) <= 26) dp[1] += 1;
        for (int i = 2; i < s.length(); i++) {
            if (s.charAt(i - 1) == '0' && s.charAt(i) == '0') return 0;
            if (s.charAt(i) != '0') dp[i] += dp[i - 1];
            if (10 <= Integer.parseInt(s.substring(i - 1, i + 1)) && Integer.parseInt(s.substring(i - 1, i + 1)) <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[dp.length - 1];  
    }
}
```

自顶向下

```python [2]
import functools
class Solution:
    @functools.lru_cache(None)
    def numDecodings(self, s: str) -> int:
        if not s:
            return 1
        ans = 0
        if len(s) >= 1 and s[0] != '0':
            ans += self.numDecodings(s[1:])
        if len(s) >= 2 and s[0] != '0' and int(s[:2]) <= 26:
            ans += self.numDecodings(s[2:])
        return ans
```



