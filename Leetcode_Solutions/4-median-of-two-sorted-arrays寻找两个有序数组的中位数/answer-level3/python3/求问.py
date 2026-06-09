### 解题思路
此处撰写解题思路
求问我的时间复杂度符合要求吗，为什么会相对慢一些，是因为pop函数吗
### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: [int], nums2: [int]) -> float:
        l = []
        n = 0
        if (len(nums1)+len(nums2))%2 == 0:
            n = 1
        for i in range((len(nums1)+len(nums2))//2+1):
            if len(nums1) == 0 and len(nums2)!=0:
                l.append(nums2.pop(0))
            elif len(nums1) != 0 and len(nums2) == 0:
                l.append(nums1.pop(0))
            else:
                if nums1[0] > nums2[0]:
                    l.append(nums2.pop(0))
                else:
                    l.append(nums1.pop(0))
        if n == 1:
            return (l[-1]+l[-2])/2
        else:
            return l[-1]
```