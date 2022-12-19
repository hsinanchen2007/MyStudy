```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        # 将两数组按长度排序，令 m > n 恒成立
        if n > m:
            m, n, nums1, nums2 = n, m, nums2, nums1
        half_len = (m + n) // 2

        # 当 nums2 为空列表
        if n == 0:
                if m % 2 == 0:
                    return (nums1[half_len] + nums1[half_len-1]) / 2
                else:
                    return nums1[half_len]

        # 当无空列表
        for i in (range(half_len - n, half_len + 1)):
            j = half_len - i
            # left_max, right_min = 0, 0

            if i - 1 < 0:
                left_max = nums2[j - 1]
            elif j - 1 < 0:
                left_max = nums1[i - 1]
            else:
                left_max = max(nums1[i - 1], nums2[j - 1])

            if j == n:
                right_min = nums1[i]
            elif i == m:
                right_min = nums2[j]
            else:
                right_min = min(nums1[i], nums2[j])

            if left_max <= right_min:
                if (m + n) % 2 == 0:
                    return (left_max + right_min) / 2
                else:
                    return right_min
```
