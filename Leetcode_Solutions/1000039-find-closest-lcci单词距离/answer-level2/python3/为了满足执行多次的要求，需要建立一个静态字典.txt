### 解题思路

![image.png](https://pic.leetcode-cn.com/a9fe8c63e7cb2009bccb97ab903872137c49e4872a61b4f6e7d043c9bee7ec19-image.png)

### 代码

```python3
class Solution:

    def __init__(self):
        self.mem = {}
        self.initialized = False

    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        if word1 not in words or word2 not in words:
            return None

        # 只初始化一次
        if not self.initialized:
            for i in range(len(words)):
                if words[i] not in self.mem:
                    self.mem[words[i]] = [i]
                else:
                    self.mem[words[i]].append(i)
            for k in self.mem:
                self.mem[k].sort()
            self.initialized = True
        if self.mem[word1][-1] < self.mem[word2][0]:
            return self.mem[word2][0] - self.mem[word1][-1]
        elif self.mem[word1][0] > self.mem[word2][-1]:
            return self.mem[word1][0] - self.mem[word2][-1]
        else:
            min_dist = float('inf')
            for i in self.mem[word1]:
                for j in self.mem[word2]:
                    if abs(i - j) < min_dist:
                        min_dist = abs(i - j)
            return min_dist
```