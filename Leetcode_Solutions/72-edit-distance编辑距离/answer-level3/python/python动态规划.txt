自荐，感觉写法要比官解好理解一些
```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if not word1 or not word2:
            return max(len(word1),len(word2))

        m = len(word1)
        n = len(word2)
        result = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            result[i][-1] = 99999999999
        for i in range(n + 1):
            result[-1][i] = 99999999999
        for i in range(m):
            for j in range(n):
                if word1[i] == word2[j]:
                    # 如果word[i]==word[j],则word[i-1][j-1]的步数即所求步数
                    # 为了处理越界问题可以用max(i,j)来处理，表示一个长度为i的字符串==>长度为j的字符串
                    # 最多只需要max(i,j)步
                    result[i][j] = min(max(i, j), result[i - 1][j - 1])
                else:
                    # 如果word[i]!=word[j]
                    result[i][j] = min(max(i + 1, j + 1), result[i - 1][j - 1] + 1, result[i][j - 1] + 1,result[i - 1][j] + 1)
        return result[m - 1][n - 1]
```
