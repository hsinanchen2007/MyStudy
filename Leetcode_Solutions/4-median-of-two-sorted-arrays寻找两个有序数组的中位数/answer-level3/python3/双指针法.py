### 解题思路
双指针法，每次比较指针`(i,j)`所在位置后面的两个数值`nums1[i + 1], nums2[j + 1]`，若一边无值则右移另一指针，若两边都有值则右移较小的一边的指针

![image.png](https://pic.leetcode-cn.com/5e22287b3498b3763217db03aa18207dbe7d38e4f05cc7ffbcab3fa3d861572a-image.png)


### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i, j = -1, -1
        total = len(nums1) + len(nums2)
        m1, m2 = 0, 0
        while i + j + 1 < total // 2:
            m2 = m1
            if i + 1 >= len(nums1):
                j += 1
                m1 = nums2[j]
            elif j + 1 >= len(nums2):
                i += 1
                m1 = nums1[i]
            elif nums1[i + 1] < nums2[j + 1]:
                i += 1
                m1 = nums1[i]
            else:
                j += 1
                m1 = nums2[j]
        if total % 2 == 0:
            return (m1 + m2) / 2.0
        else:
            return m1


```