### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        """
        动态规划
        :param word1:
        :param word2:
        :return:
        """
        m = len(word1)
        n = len(word2)
        word_list = [[0 for i in range(n + 1)] for j in range(m + 1)]
        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0:
                    word_list[i][j] = j
                elif j == 0:
                    word_list[i][j] = i
                elif word1[i - 1] == word2[j - 1]:
                    word_list[i][j] = 1 + min(word_list[i - 1][j], word_list[i][j - 1], word_list[i - 1][j - 1] - 1)
                else:
                    word_list[i][j] = 1 + min(word_list[i - 1][j], word_list[i][j - 1], word_list[i - 1][j - 1])

        return word_list[m][n]

```