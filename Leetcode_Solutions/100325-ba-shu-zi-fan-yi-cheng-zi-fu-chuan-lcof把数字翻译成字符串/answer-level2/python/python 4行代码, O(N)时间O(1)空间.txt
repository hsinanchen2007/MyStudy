### 解题思路

- 动态规划
- dp[i] = dp[i-2] (使用2个字符) + dp[i-1] (使用1个字符) if 10 <= int(s[i - 1:i + 1]) <= 25 else dp[i-1]
- 可以只使用两个变量表示上一个和当前的翻译方法数目

### 代码

```python3

class Solution:
    def translateNum(self, num: int) -> int:
        s, a, b = str(num), 1, 1
        for i in range(1, len(s)):
            a, b = b, ((a+b) if 10 <= int(s[i - 1:i + 1]) <= 25 else b)
        return b
```