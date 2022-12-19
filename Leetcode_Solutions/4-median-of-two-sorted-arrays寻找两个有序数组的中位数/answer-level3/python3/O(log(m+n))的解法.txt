### 解题思路
每次都求k//2，一直递归即可

### 代码

```python3
from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        """
        两个有序数组求中位数，问题一般化为，求两个有序数组的第k个数，当k = (m+n)/2时为原问题的解。
        怎么求第k个数？分别求出第一个和第二个数组的第 k / 2个数 a 和 b，然后比较 a 和 b，当a < b ，
        说明第 k 个数位于 a数组的第 k / 2个数后半段，或者b数组的 第 k / 2 个数前半段，问题规模缩小了一半，
        然后递归处理就行。

        时间复杂度是 O(log(m+n))
        :param nums1:
        :param nums2:
        :return:
        """
        m, n = len(nums1), len(nums2)
        # 处理m或n为空的情况
        if m == 0:
            if n & 1 == 0:
                return (nums2[n // 2] + nums2[n // 2 - 1]) / 2
            return nums2[n // 2]
        if n == 0:
            if m & 1 == 0:
                return (nums1[m // 2] + nums1[m // 2 - 1]) / 2
            return nums1[m // 2]
        total = m + n
        # 总数为奇数，找第total//2 + 1个数
        if total & 1 == 1:
            return self.find_k(nums1, 0, nums2, 0, total // 2 + 1)
        # 总数为偶数，找第 total // 2 个数和第total // 2 + 1个数的平均值
        return (self.find_k(nums1, 0, nums2, 0, total // 2) + self.find_k(nums1, 0, nums2, 0,
                                                                          total // 2 + 1)) / 2

    def find_k(self, a, a_begin, b, b_begin, k):
        """寻找数组a和数组b中，第k个数字"""
        # 当a或b超过数组长度，则第k个数为另外一个数组第k个数
        if a_begin >= len(a):
            return b[b_begin + k - 1]
        if b_begin >= len(b):
            return a[a_begin + k - 1]
        # 当k为1时，两数组 最小的那个为第一个数
        if k == 1:
            return min(a[a_begin], b[b_begin])
        mid_a = mid_b = max(a[-1], b[-1]) + 1
        # mid_a  mid_b 分别表示a数组、b数组中第 k //  2 个数
        if a_begin + k // 2 - 1 < len(a):
            mid_a = a[a_begin + k // 2 - 1]
        if b_begin + k // 2 - 1 < len(b):
            mid_b = b[b_begin + k // 2 - 1]
        # 如果a数组的第k//2个数小于b数组的第k//2个数，表示 总的第k个数位于a的第k//2个数的
        # 后半段，或者是b的第k//2个数的前半段
        # 由于范围缩小了 k//2个数，此时总的第k个数实际上等于新范围内的第k - k//2 个数，依次递归
        if mid_a <= mid_b:
            return self.find_k(a, a_begin + k // 2, b, b_begin, k - k // 2)
        # 否则相反
        return self.find_k(a, a_begin, b, b_begin + k // 2, k - k // 2)

    def findMedianSortedArrays1(self, nums1: List[int], nums2: List[int]) -> float:
        """
         中位数是左右两个的数的个数相等，如果是偶数个就取中间两个数的和除以2
         这个时间复杂度不满足O(long(m+n))  m,n为两个数组的长度
        :param nums1:
        :param nums2:
        :return:
        """
        new_list = list()
        i = j = 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] <= nums2[j]:
                new_list.append(nums1[i])
                i += 1
            else:
                new_list.append(nums2[j])
                j += 1
        while i < len(nums1):
            new_list.append(nums1[i])
            i += 1
        while j < len(nums2):
            new_list.append(nums2[j])
            j += 1
        if len(new_list) % 2 == 0:
            middle = len(new_list) // 2
            return (new_list[middle - 1] + new_list[middle]) / 2
        else:
            return new_list[len(new_list) // 2]



```