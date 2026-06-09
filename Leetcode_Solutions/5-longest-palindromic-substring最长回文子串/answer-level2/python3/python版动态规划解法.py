最大回文子串问题是一个经典的动态规划问题，给定一个字符串s，可以从中删除一些字符，使得剩下的串是一个回文串。

```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        t = s[::-1] # 倒序
        n = len(s)
        if n == 0:
            break
        else:
            result_matrix = [[0 for i in range(n+1)] for j in range(n+1)]
            # print(result_matrix)
            # reslut[i][i] 表示子串的回文子串的长度，result[n][n]表示原串的回文子串长度
            for i in range(n):
                for j in range(n):
                    if s[i] == t[j]: # 如果相等，则回文串长度等于前一个状态+1
                        result_matrix[i+1][j+1] = result_matrix[i][j] + 1
                    else:
                        result_matrix[i+1][j+1] = max(result_matrix[i+1][j], result_matrix[i][j+1])
            print(n-result_matrix[n][n])
```