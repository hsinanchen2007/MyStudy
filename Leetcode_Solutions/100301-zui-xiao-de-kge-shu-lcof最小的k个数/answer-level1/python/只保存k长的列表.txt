### 解题思路
只保存k长的列表，在k+1：end的列表中，若有<列表中的最大值的，替换

### 代码

```python
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k==0:
            return []
        res=arr[:k]
        for i in arr[k:]:
            if i < max(res):
                res[res.index(max(res))]=i 
        return res

```