### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        memo = {}
        return self.memo_recursion(word1,word2,len(word1)-1,len(word2)-1,memo)
    def memo_recursion(self,word1,word2,idx1,idx2,memo):
        if (idx1,idx2) in memo:
            return memo[(idx1,idx2)]
        if idx1 == -1:
            memo[(idx1,idx2)] = idx2 + 1
            return idx2 + 1
        elif idx2 == -1:
            memo[(idx1,idx2)] = idx1 + 1
            return idx1 + 1

        if word1[idx1] == word2[idx2]:
            memo[(idx1,idx2)] = self.memo_recursion(word1, word2, idx1-1, idx2-1, memo)
        else:
            memo[(idx1,idx2)] = 1 + min(min(self.memo_recursion(word1,word2,idx1-1,idx2-1,memo),self.memo_recursion(word1, word2, idx1-1, idx2, memo)),self.memo_recursion(word1, word2, idx1, idx2-1, memo))
        return memo[(idx1,idx2)]
```