# [二分查找]两个有序数组中位数

## 题目
在两个排序好的数组中找到中位数；
要求时间在 Olog(N_1 + N_2)

## Solution
- 二分查找对象：本题中两个数组中位数，首先需要2个指针分配给两个数组，通过 $i + j = m + n - i - j => j = (m+n-2i) // 2$ 转化为一个指针，对齐进行二分查找；其中 `nums1: 0:i-1, i:len(nums1)-1` 切分为两部分，`nums2: 0:j-1, j:len(nums2)-1` 切分为两部分；
- 二分查找的关键是确定新的切分的条件：根据中位数定义，确定二分条件，同时也决定了边界；`nums1[i] >= nums2[j-1]`, `nums2: 0:j-1, j:len(nums2)-1`

```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # nums1: 0:i-1, i:len(nums1)-1
        # nums2: 0:j-1, j:len(nums2)-1
        # nums1[i] >= nums2[j-1]
        # nums1[i-1] <= nums2[j]
        # i + j = m + n - i - j => j = (m+n-2i) // 2
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        l1 = len(nums1)
        l2 = len(nums2)

        imin, imax = 0, l1
        while imin <= imax:
            imid = (imin + imax) // 2
            j = (l1 + l2 - 2*imid) // 2


            if imid > 0 and nums1[imid-1] > nums2[j]:
                imax = imid - 1
            elif imid < l1 and nums1[imid] < nums2[j-1]:
                imin = imid + 1
            else:
                # print(imid, j)
                if imid == 0:
                    max_left = nums2[j-1]
                elif j == 0:
                    max_left = nums1[imid-1]
                else:
                    max_left = max(nums1[imid-1], nums2[j-1])
                
                if imid == l1:
                    min_right = nums2[j]
                elif j == l2:
                    min_right = nums1[imid]
                else:
                    min_right = min(nums1[imid], nums2[j])
                
                if (l1 + l2) % 2:
                    return min_right
                return (max_left + min_right) / 2.0
```