### 解题思路

![1580743210(1).png](https://pic.leetcode-cn.com/2580cf0b80b636fe8bb1ea4fa26fef61c141992e664a2cf2d21e9c37b33592bd-1580743210\(1\).png)

### 代码

```python3
class Solution:
    from collections import Counter

    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
            #return self.intersect(nums2, nums1)

        
        nums1 = self.Counter(nums1)
        r = []
        i = 0
        for i in range(len(nums2)):
            temp = nums2[i]
            if temp in nums1 and nums1[temp] > 0:
                r.append(temp)
                nums1[temp] -= 1
                
        return r
```