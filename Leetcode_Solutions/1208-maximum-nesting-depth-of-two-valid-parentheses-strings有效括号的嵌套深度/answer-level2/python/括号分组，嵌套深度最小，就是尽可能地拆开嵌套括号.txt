### 解题思路
尽可能地拆开嵌套括号，如果相邻两个括号一样，那就把他们分到不同组，这样就是尽可能地拆开了一个嵌套，因为是分成两组，最深嵌套的深度最多被拆成一半。

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        re=[0]
        for i in range(1,len(seq)):
            if seq[i]==seq[i-1]:
                re.append(1-re[i-1])
            else:
                re.append(re[i-1])
        return re
```