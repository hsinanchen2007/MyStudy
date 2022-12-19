
```python []
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dic = {}
        for i in nums1:
            try:
                if dic[i]:
                    dic[i]+=1
            except KeyError:
                dic[i] = 1
        res = []        
        for j in nums2:
            try:
                if dic[j]:
                    dic[j]-=1
                    res.append(j)
            except KeyError:
                pass
                
                    
        return res
```

其实有点像java的map?

