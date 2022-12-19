### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        i1,i2 = [],[]
        for i in range(len(words)):
            if words[i] == word1:
                i1.append(i)
            if words[i] == word2:
                i2.append(i)
        min = float("inf")
        for j1 in i1:
            for j2 in i2:
                if abs(j1-j2)<min:
                    min =  abs(j1-j2)
        return min
```