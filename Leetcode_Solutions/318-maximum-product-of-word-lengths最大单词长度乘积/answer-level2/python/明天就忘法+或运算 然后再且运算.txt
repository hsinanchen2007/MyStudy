### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n=len(words)
        if not words or n<0:
            return 0
        val=[0]*n
        for i in range(n):
            for j in range(len(words[i])):
                # 左移来 或
                val[i]|=1<<(ord(words[i][j])-ord("a"))
        maxs=0
        for i in range(n):
            for j in range(i+1,n):
                if val[i]&val[j]==0:
                    maxs=max(maxs,len(words[i])*len(words[j]))
        return maxs
```