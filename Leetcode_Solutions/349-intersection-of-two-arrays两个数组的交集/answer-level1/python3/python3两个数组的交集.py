![image.png](https://pic.leetcode-cn.com/69ec8ca7639926cc07783001a1dd150bbe1d0e6d12aad7e61433a535892f5f6a-image.png)

```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        i,j=0,0
        res=[]
        while i<len(nums1) and j<len(nums2):
            if nums1[i]<nums2[j]:
                i+=1
            elif nums1[i]>nums2[j]:
                j+=1
            else:
                res.append(nums1[i])
                i+=1
                j+=1
        return list(set(res))
```

