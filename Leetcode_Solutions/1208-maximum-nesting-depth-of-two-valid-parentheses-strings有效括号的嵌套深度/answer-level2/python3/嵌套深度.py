

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:

        cnt = 1
        res = []
        for c in seq:
            if c == '(':
                cnt += 1
                res.append(cnt&1)
            else:
                res.append(cnt&1)
                cnt -= 1
        return res



```