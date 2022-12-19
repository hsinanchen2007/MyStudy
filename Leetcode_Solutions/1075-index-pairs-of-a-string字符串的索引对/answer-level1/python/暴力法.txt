### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def indexPairs(self, text: str, words: List[str]) -> List[List[int]]:
        res = []
        for i in range(len(text)):
            for j in range(i, len(text)):
                if text[i:j+1] in words:
                    res.append([i,j])
        return res
```