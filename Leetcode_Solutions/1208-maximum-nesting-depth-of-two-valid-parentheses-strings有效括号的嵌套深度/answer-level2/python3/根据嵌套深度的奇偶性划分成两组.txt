### 解题思路
根据嵌套深度的奇偶性划分成两组

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        d=0
        res=[]
        for i in seq:
            if i=='(':
                d+=1
                res.append(1-d%2)
            else:
                res.append(1-d%2)
                d-=1
        return res
```