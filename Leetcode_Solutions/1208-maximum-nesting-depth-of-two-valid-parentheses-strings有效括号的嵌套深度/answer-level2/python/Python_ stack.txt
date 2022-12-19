### 解题思路
遍历字符串，如果字符为"("，那么该字符应该分到与前字符不同的子字符串，如果是")"，则应该分到与之匹配的"("所在的子字符串。

### 代码

```python
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        res, s = [], []
        for c in seq:
            if c == '(':
                s.append(c)
                res.append(len(s)%2)
            else:
                res.append(len(s)%2)
                s.pop()      
        return res
            
```