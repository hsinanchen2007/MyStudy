### 解题思路
官方思路

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans=[]
        d=0
        for c in seq:
            if c=='(':
                d+=1
                ans.append(d%2)
            if c==')':
                ans.append(d%2)
                d-=1
        return ans
```