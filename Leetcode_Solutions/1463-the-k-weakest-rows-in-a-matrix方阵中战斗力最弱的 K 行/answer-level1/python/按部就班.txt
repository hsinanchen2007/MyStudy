### 解题思路
就正常做

### 代码

```python
class Solution(object):
    def kWeakestRows(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        res=[x.count(1) for x in mat]
        res=[(i,num) for i,num in enumerate(res)]
        res.sort(key=lambda x:x[1])
        # print res
        return [x[0] for x in res[:k]]
```