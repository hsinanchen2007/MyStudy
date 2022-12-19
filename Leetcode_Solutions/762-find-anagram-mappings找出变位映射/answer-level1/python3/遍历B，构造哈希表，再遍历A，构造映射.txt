### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def anagramMappings(self, A: List[int], B: List[int]) -> List[int]:
        from collections import defaultdict
        mdict = defaultdict(list)
        res = []
        for i,j in enumerate(B):
            mdict[j].append(i)
        for i in A:
            res.append(mdict[i][0])
        return res
```