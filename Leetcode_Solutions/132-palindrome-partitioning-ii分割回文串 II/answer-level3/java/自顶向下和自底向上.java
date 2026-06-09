## 思路:

动态规划,

思路一: 自顶向下

```python
import functools
class Solution:
    @functools.lru_cache(None)
    def minCut(self, s: str) -> int:
        if s == s[::-1]:
            return 0
        ans = float("inf")
        for i in range(1, len(s) + 1):
            if s[:i] == s[:i][::-1]:
                ans = min(self.minCut(s[i:]) + 1, ans)
        return ans
```

思路二: 自底向上

可以通过[5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)([题解链接](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/duo-chong-si-lu-qiu-jie-by-powcai))和[131. 分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/)([题解链接](https://leetcode-cn.com/problems/palindrome-partitioning/solution/dong-tai-gui-hua-dfs-by-powcai))看一下关于`dp`的写法

再用数组`min_s`记录到字符串到`i`位置需要分割次数.

```python [1]
class Solution:
    def minCut(self, s: str) -> int:
        min_s = list(range(len(s)))
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        for i in range(n):
            for j in range(i+1):
                if s[i] == s[j] and (i - j < 2 or dp[j + 1][i - 1]):
                    dp[j][i] = True
                    # 说明不用分割
                    if j == 0:
                        min_s[i] = 0
                    else:
                        min_s[i] = min(min_s[i], min_s[j - 1] + 1)
        return min_s[-1]
```



```java [1]
class Solution {
    public int minCut(String s) {
        int n = s.length();
        int[] min_s = new int[n];
        boolean[][] dp = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            min_s[i] = i;
            for (int j = 0; j <= i; j++) {
                if (s.charAt(i) == s.charAt(j) && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    min_s[i] = j == 0 ? 0 : Math.min(min_s[i], min_s[j - 1] + 1);
                }
            }
        }
        return min_s[n - 1];
    }
}
```

