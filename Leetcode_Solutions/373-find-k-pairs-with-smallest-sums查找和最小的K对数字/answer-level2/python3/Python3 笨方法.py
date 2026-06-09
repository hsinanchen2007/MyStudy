```
class Solution:
    def kSmallestPairs(self, nums1, nums2, k: int):
        a = []
        for i in nums1:
            for j in nums2:
                a.append([i, j])
        a.sort(key=sum)
        return a[:k]
```
