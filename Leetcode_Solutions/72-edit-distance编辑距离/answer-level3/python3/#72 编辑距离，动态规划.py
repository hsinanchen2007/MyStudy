### 解题思路
时间复杂度：O(n^2)
空间复杂度：O(n)
假设word1长度永远小于等于word2，利用两个长度为len(word1)+1的数组来存储动态编辑距离。循环第i轮的current[j]表示word2[:i]到word1[:j-1]的最短编辑距离。遍历过程中，如果word2[i]的字符和word1[j-1]的字符一样，那么不需要编辑，此时的编辑距离为last[j-1]，如果字符不一样，说明需要编辑，有三种编辑方式可选（1.在word2插入一个字符：此时编辑距离为current[j-1]+1；2.在word2删除一个字符：此时编辑距离为last[j]+1；3.替换word2的一个字符：此时编辑距离为last[j-1]+1），选择开销最小的那一种。
### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if not word1 and not word2:
            return 0

        if len(word1) > len(word2):
            word1, word2 = word2, word1

        last = [0] * (len(word1) + 1)
        for i in range(1, len(last)):
            last[i] = last[i - 1] + 1

        for i in range(len(word2)):
            current = [0] * (len(last))
            for j in range(len(last)):
                if j == 0:
                    current[j] = last[j] + 1
                    continue
                if word2[i] == word1[j - 1]:
                    current[j] = last[j - 1]
                else:
                    current[j] = min(last[j - 1], last[j], current[j - 1]) + 1

            last = current

        return last[-1]
```