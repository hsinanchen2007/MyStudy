```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # 典型的动态规划问题
        dpTable = [[i] * (len(word1) + 1) for i in range(len(word2) + 1)]
        # 初始状态
        # 第一行
        dpTable[0] = [i for i in range(len(word1) + 1)]
        # 第一列初始化完了
        for i in range(1, len(word2) + 1):
            for j in range(1, len(word1) + 1):
                # 判断最后一位（新增加的）和之前的关系
                if word2[i - 1] == word1[j - 1]:
                    # 不变
                    dpTable[i][j] = dpTable[i - 1][j - 1]
                else:
                    # 替换，删除，插入
                    dpTable[i][j] = min(dpTable[i - 1][j], dpTable[i][j - 1], 
                    dpTable[i - 1][j - 1]) + 1
        return dpTable[-1][-1]
```