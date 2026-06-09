解题思路：借鉴并归排序交叉合并两数组构成新的有序数组，然后寻找中位数。
方法：给定计数变量m和n，依次添加nums1和nums2中小的值构成有序数组，题目要求寻找中位数，所以新数组元素个数超过nums1和nums2长度之和的一半即可，根据nums1和nums2长度和的奇偶性确定返回值，和为奇数返回新数组最后一位，否则返回最后两位平均值。
```
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        new_nums = []
        m, n = 0, 0
        while len(new_nums) <= (len(nums1) + len(nums2)) / 2:   # 中位数，新有序数组长度超过两数组长度和的一半即可
            # 边界，处理其中一个数组全部拿空的情况
            if m == len(nums1):
                new_nums.append(nums2[n])
                n += 1
            elif n == len(nums2):
                new_nums.append(nums1[m])
                m += 1
            # 小的值添加到新有序数组，计数变量加1
            elif nums1[m] <= nums2[n]:
                new_nums.append(nums1[m])
                m += 1
            elif nums1[m] > nums2[n]:
                new_nums.append(nums2[n])
                n += 1
        # 根据nums1和nums2长度和的奇偶性确定返回值
        if (len(nums1) + len(nums2)) % 2 == 1:
            return new_nums[-1]
        else:
            return (new_nums[-1] + new_nums[-2]) / 2.0
```
