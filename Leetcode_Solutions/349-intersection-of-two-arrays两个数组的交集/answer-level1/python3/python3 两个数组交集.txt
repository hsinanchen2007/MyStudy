思路1，直接暴力
```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        for i in nums1:
            if i in nums2 and i not in res:
                res.append(i)
        return res
```
思路2，python中 set()提供直接求交集的方式
```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return set(nums1)&set(nums2)
```
