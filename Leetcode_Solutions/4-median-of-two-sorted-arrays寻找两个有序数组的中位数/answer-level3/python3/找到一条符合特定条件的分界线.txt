```
# -*- coding: utf-8 -*-

from typing import List

"""
思路:
1. 假设nums1的长度为len1, nums2的长度为len2, 那么找中位数问题可以转化为找第k个值
(1) nums1+nums2为奇数, 找第int((len1+len2+1)/2)个
(2) nums1+nums2位偶数, 找第int((len1+len2)/2)个和第int((len1+len2+2)/2)
2. 由于num1和num2都是有序的, 考虑最一般情况, 找到的值位于nums1的第x个, 且x小于k,那么
nums2的第k-x个元素,和nums1的第k个元素,实际上构成了一个分界线, 左边一共k个值, 且左边最
大小于右边最小
3. 题目描述nums1和nums2不会同时为空, 建议把nums1选为较短的那个, 一是二分搜索快, 二是
需要考虑的特殊边界情况更少一些.
"""
class Solution:

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int])->float:

        def find_k(nums1: List[int], nums2: List[int], k:int)->int:
            len1, len2 = len(nums1), len(nums2)
            if len1 > len2:
                nums1, len1, nums2, len2 = nums2, len2, nums1, len1

            # 现在 nums1已经是较短的那个了
            # 考虑边界条件, nums1为空

            if len1 == 0:
                return nums2[k-1]

            # 在nums1中二分查找一个索引, 使得左边的元素(包括自己)和对应算出来的nums2的
            # 左边的元素全都小于分界线右边的元素

            left = 0
            right = len1-1

            while left <= right:

                mid1 = int((left+right)/2)
                # 这里用的是索引, 所以算上mid1, 左边元素个数就是mid1+1
                # 对应地nums2左边元素应该是k-mid1-1个, 索引k-mid1-2
                mid2 = k-mid1-2
                print(left, right, mid1, mid2)
                # 由于mid1肯定在有效范围内, 这里只需要去分析mid2的各种特殊情况
                # 比如nums2为: 1, 2, 3, 4, 索引范围0-3
                # 有效的情况为都不包含, 包含部分, 全都包含
                # 对应临界点mid2为-1(小于则nums1选多了), -1和3之间, 3(大于则nums1选少了)
                if mid2 < -1:
                    right = mid1-1
                    continue
                if mid2 > len2-1:
                    left = mid1+1
                    continue
                # 有效的情况也得考虑边界, 比如在最左边的时候, 那么左最大用-inf
                # 在最右边的时候, 右边最小用inf
                lmax1 = nums1[mid1] if mid1 in range(len1) else float('-inf')
                rmin1 = nums1[mid1+1] if mid1+1 in range(len1) else float('inf')
                lmax2 = nums2[mid2] if mid2 in range(len2) else float('-inf')
                rmin2 = nums2[mid2+1] if mid2+1 in range(len2) else float('inf')

                print(lmax1, rmin1, lmax2, rmin2)
                # 如果左边最大小于等于右边最小, 说明找对了
                if lmax1 <= rmin2 and lmax2 <= rmin1:
                    return max(lmax1, lmax2)
                elif lmax1 > rmin2:
                    right = mid1-1
                    continue
                else:
                    left = mid1+1
                    continue
            # 理想情况下, 经过上述循环, 分界线已经找到了
            # 特殊情况是nums1没有满足条件的分界点, 即right找到-1了
            # 注意, left找到len1-1右边的情况不用考虑,因为mid1认为是归到左边的
            if right == -1:
                return nums2[k-1]

        len1, len2 = len(nums1), len(nums2)
        if (len1+len2) % 2 == 1:
            return float(find_k(nums1, nums2, int((len1+len2+1)/2)))
        else:
            k1 = find_k(nums1, nums2, int((len1+len2)/2))
            k2 = find_k(nums1, nums2, int((len1+len2+2)/2))
            return float((k1+k2)/2)
```
