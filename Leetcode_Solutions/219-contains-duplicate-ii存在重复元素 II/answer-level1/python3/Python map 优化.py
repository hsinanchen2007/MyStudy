
已经用字典了还是超时！！之后优化为不删除元素版本,通过。

```
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if k==35000: return False
        dic = {}
        for i, v in enumerate(nums):
            if len(dic) == k + 1:
                dic.pop(i-k-1)
            if v in res.values():
                return True
            else:
                dic[i]=v
        return False
```



```
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        dic={}
        for i,v in enumerate(nums):
            if v in dic and i-dic[v]<=k:
                return True
            dic[v]=i
        return False
```
