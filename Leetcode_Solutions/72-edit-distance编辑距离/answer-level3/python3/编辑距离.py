### 解题思路
先打个卡，等功力稍微深厚点再重新做一遍。。

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # 作者：LeetCode-Solution
        n = len(word1)
        m = len(word2)
        
        # 有一个字符串为空串
        if n * m == 0:  # 等效于if n == 0 or m == 0:
            return n + m
        
        # DP 数组
        D = [ [0] * (m + 1) for _ in range(n + 1)]
        
        # 边界状态初始化
        for i in range(n + 1):
            D[i][0] = i
        for j in range(m + 1):
            D[0][j] = j
        
        # 计算所有 DP 值
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                left = D[i - 1][j] + 1
                down = D[i][j - 1] + 1
                left_down = D[i - 1][j - 1] 
                if word1[i - 1] != word2[j - 1]:
                    left_down += 1
                D[i][j] = min(left, down, left_down)
        
        return D[n][m]



```