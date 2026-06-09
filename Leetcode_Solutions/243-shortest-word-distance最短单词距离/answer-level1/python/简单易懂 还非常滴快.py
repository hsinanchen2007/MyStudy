### 解题思路
1. 使用变量记忆搜索的中间结果
2. 由局部最优解在遍历过程中得到全局最优解

### 代码

```python3
class Solution:
    def shortestDistance(self, words: List[str], word1: str, word2: str) -> int:
        start, end, res = -1, -1, len(words)
        for i in range(len(words)):
            if words[i] == word1:
                start = i  
            if words[i] == word2:
                end = i
            if start != -1 and end != -1:
                res = min(res,abs(end-start))
        return res
```