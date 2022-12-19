### 解题思路
官方题解，python实现。
利用先验知识，中位数的位置在中间。只需要在其中一个数组中进行二分查找，另一个数组的相应位置可以通过计算得出。中位数满足的条件是，左边的部分永远小于右边的部分。
这样便不需要nums1+nums2中一起查找。时间复杂度便降为O(log(min(m,n))


### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        if m > n:
            return self.findMedianSortedArrays(nums2,nums1)
        hi = m
        lo = 0
        while lo <= hi:
            i = (hi + lo + 1)//2
            j = (m + n + 1)//2 - i
            left_nums1_max = -float('inf') if i == 0 else nums1[i-1]
            right_nums1_min = float('inf') if i == m else nums1[i]
            left_nums2_max = -float('inf') if j == 0 else nums2[j-1]
            right_nums2_min = float('inf') if j == n else nums2[j]
            if left_nums1_max <= right_nums2_min and left_nums2_max <= right_nums1_min:
                if (m+n)%2 == 0:
                    return (max(left_nums1_max,left_nums2_max) + min(right_nums1_min,right_nums2_min))/2
                else:
                    return max(left_nums1_max,left_nums2_max)
            elif left_nums1_max > right_nums2_min:
                hi = i - 1
            else:
                lo = i + 1
        return 0.0
```