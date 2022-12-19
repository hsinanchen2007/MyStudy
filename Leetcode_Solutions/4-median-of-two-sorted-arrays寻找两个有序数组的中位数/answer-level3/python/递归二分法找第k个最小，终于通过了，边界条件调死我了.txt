### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def findKmid(nums1, nums2, k):
            if len(nums1) == 0:
                return nums2[k - 1]
            elif len(nums2) == 0:
                return nums1[k - 1]
            else:
                if k == 1:
                    return nums1[0] if nums1[0] < nums2[0] else nums2[0]
                m = k>>1
                if len(nums1) < m:
                    m1 = len(nums1) - 1
                    m2 = k - len(nums1) - 1
                elif len(nums2) < m:
                    m1 = k - len(nums2) - 1
                    m2 = len(nums2) - 1
                else:
                    m1 = m2 = m - 1
                if nums1[m1] < nums2[m2]:
                    k = findKmid(nums1[m1+1:], nums2, k - m1 - 1)
                else:
                    k = findKmid(nums1, nums2[m2+1:], k - m2 - 1)
                return k
        
        mid = (len(nums1)+len(nums2)+1)>>1
        if (len(nums1) + len(nums2)) % 2 == 1:
            k = findKmid(nums1, nums2, mid)
        else:
            k = (findKmid(nums1, nums2, mid) + findKmid(nums1, nums2, mid+1)) / 2
        return k

            

```