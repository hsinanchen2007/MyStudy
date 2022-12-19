### 解题思路
二分法，递归算法

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        m = len(nums1)
        n = len(nums2)
        left = (m + n + 1) // 2
        right = (m + n + 2) // 2
        result = (self.findekth(nums1, 0, nums2, 0, left) + self.findekth(nums1, 0, nums2, 0, right)) / 2.0
        return result

    def findekth(self, num1, i, num2, j, k):
        if i > len(num1) - 1:
            return num2[j + k - 1]
        if j > len(num2) - 1:
            return num1[i + k - 1]
        if k == 1:
            return min(num1[i], num2[j])

        midval1 = num1[i + k // 2 - 1] if (i + k // 2 - 1) < len(num1) else sys.maxsize
        midval2 = num2[j + k // 2 - 1] if (j + k // 2 - 1) < len(num2) else sys.maxsize

        if midval1 < midval2:
            return self.findekth(num1, i + k // 2, num2, j, k - k // 2)
        else:
            return self.findekth(num1, i, num2, j + k // 2, k - k // 2)

```