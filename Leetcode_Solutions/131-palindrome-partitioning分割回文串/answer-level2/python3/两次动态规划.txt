### 解题思路

两次DP，第一次DP求出字符串中所有的回文串，时间复杂度$O(n ^ 2)$，

得到了`[i, j]`是不是回文串之后，从后先前扫描，rec[i] 表示[i : len(s)] 区间的所有的划分方法

那么rec[i-1] 就是遍历j从i 到 len(s), 如果s[i:j]是回文串的话，就将s[i:j]和rec[j + 1]的所有划分方法拼接起来得到

就转换为了子问题


时间复杂度$O(n^2) + O(n^3) = O(n^3)$

空间复杂度$O(n^3)$


### 代码

```python3
class Solution:
    def partition(self, s: str):

        l = len(s)
        dp = [[False] * l for _ in range(l)]   # 记录[i-j]是不是回文串
        for i in range(l):
            dp[i][i] = True
        for i in range(l - 1):
            if s[i] == s[i + 1]:
                dp[i][i+1] = True
        for _len in range(3, l + 1):
            for i in range(l - _len + 1):
                dp[i][i + _len - 1] = (s[i] == s[i + _len - 1] and dp[i + 1][i + _len - 2])

        rec = [[] for _ in range(l + 1)]  # 逆向扫描 得到划分结果
        for i in range(l - 1, -1, -1):
            for j in range(i, l - 1):
                if dp[i][j]:
                    for xx in rec[j + 1]:
                        rec[i].append([s[i:j + 1]] + xx)

            if dp[i][l - 1]:
                rec[i].append([s[i:l]])

        return rec[0]
```