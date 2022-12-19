我把答案也整理到了我的 github 中，欢迎 follow：[https://github.com/lubobill1990/leetcode/blob/master/p4.README.md](https://github.com/lubobill1990/leetcode/blob/master/p4.README.md)

看了各位的解法，发现所有的解法，临界条件都很复杂，纵使是老司机，也需要费些时间才能看懂。

同时，很多同学的代码缺乏结构性，可读性较差。

我这里提供一个新的思路，**避开了复杂的临界条件**。同时代码中，每一块有清晰的目标。供大家参考。

# 思路来源

由于计算复杂度是 log，所以第一反应就是要和二分法联系起来。

二分法的本质是，每次都将问题的空间缩小一半。

# 解法思路：
1. 分别找到两个数组（剩余部分）的中位数，以及用来计算中位数的数字的位置（姑且称为**中位数计算元素**）。当长度为奇数是，中位数计算元素就是一个，当长度为偶数时，就是两个。
2. 找到了中位数，我们就可以确定，最终的中位数值肯定在两个数组各自的中位数之间。
3. 那么我们可以**尝试缩小两个数组的搜索范围**：
  1. 比较两个数组的中位数，如果第一个数组的中位数大于第二个数组的中位数，就可以删除第一个数组**中位数计算元素**的右侧，和第二个数组**中位数计算元素**左侧
  2. 删除的长度为**两个数组中较短的一个的中位数计算元素一侧的长度**
4. 如此**迭代直到有一个数组只包含了中位数计算元素**
5. 这时候，我们可以保证，最终的中位数，肯定在另一个数组的**中位数计算元素**左右附近的几个元素，和**当前只剩中位数计算元素**的数组中。
6. 所以从另一个数组中位数计算元素附近两边取额外 4 个元素组成数组，加上当前没有可删元素的数组，排序，直接取中位数。

# 复杂度分析：
迭代，直到一个数组的中位数计算元素两侧没有可删除的元素，需要约 log(min(m,n)) 次，每一次迭代常数次操作，复杂度为 O(log(min(m,n)))
迭代结束后直接缩减另一个数组的空间到约 10 个元素需要常数次操作，复杂度为 O(1)
最后混合两个数组，排序两个数组，因为元素个数只有 12 个左右，所以只需要常数次操作，复杂度为 O(1)
整个解决方案的复杂度为 O(log(min(m,n))) + O(1) + O(1) = O(log(min(m,n)))

# 简化问题的关键

1. 问题复杂度缩小到 10 个所有，直接跳过临界条件，合并数组取中位数是最大的亮点，直接让代码变得非常易读
2. 将获取中位数和中位数两侧的位置抽取到方法中，提升了可读性，降低了出错率

```
import math

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums1_start_pos = 0
        nums1_end_pos = len(nums1) - 1

        nums2_start_pos = 0
        nums2_end_pos = len(nums2) - 1

        while True:
            # 为了避免复杂的临界条件，当两个数组剩下的部分非常短的时候，降级为从两个数组合并且排序后直接取中位数
            if nums1_end_pos - nums1_start_pos < 15 and nums2_end_pos - nums2_start_pos < 15:
                merged = sorted(nums1[nums1_start_pos:nums1_end_pos + 1] + nums2[nums2_start_pos:nums2_end_pos + 1])
                median, length_from_start_to_median = self.getMedianInfo(merged, 0, len(merged) - 1)
                return median

            median1, length_from_start_to_median1 = self.getMedianInfo(nums1, nums1_start_pos, nums1_end_pos)

            median2, length_from_start_to_median2 = self.getMedianInfo(nums2, nums2_start_pos, nums2_end_pos)

            # 如果两个中位数相等，则直接返回中位数
            if median1 == median2:
                return median1

            # 其中一个数组的中位数两边已经没有可以删除的数字了，则另一个数组可以只留中位数两边少数几个数
            if length_from_start_to_median1 == 0:
                length_from_start_to_median2 = max(length_from_start_to_median2 - 4, 0)
                nums2_start_pos = nums2_start_pos + length_from_start_to_median2
                nums2_end_pos = nums2_end_pos - length_from_start_to_median2
                continue
            elif length_from_start_to_median2 == 0:
                length_from_start_to_median1 = max(length_from_start_to_median1 - 4, 0)
                nums1_start_pos = nums1_start_pos + length_from_start_to_median1
                nums1_end_pos = nums1_end_pos - length_from_start_to_median1
                continue

            # 从两个数组的中位数两边试图删掉元素，指数级降低问题搜索空间
            if median1 > median2:
                # 如果数组1 的中位数大于数组2 的中位数
                # 那么删除数组1 右边的数，数组2 左边的数
                # 删除的数个数为数组1 和数组2 已经找出的中位数两边较小的个数
                nums1_end_pos = nums1_end_pos - min(length_from_start_to_median1, length_from_start_to_median2)
                nums2_start_pos = nums2_start_pos + min(length_from_start_to_median1, length_from_start_to_median2)
            elif median1 < median2:
                nums1_start_pos = nums1_start_pos + min(length_from_start_to_median1, length_from_start_to_median2)
                nums2_end_pos = nums2_end_pos - min(length_from_start_to_median1, length_from_start_to_median2)

    def getMedianInfo(self, nums, start_pos, end_pos):
        """
        给定数组
        获取数组的中位数
        以及数组中，用来计算中位数的数的左侧数的左边元素的个数，这个数和右侧数右边的元素个数是一样的
        后面会基于这个数，试图从数组中删掉一侧的元素，减小问题空间
        """
        half_position = float(start_pos + end_pos) / 2
        left_position = int(math.floor(half_position))
        if half_position - left_position < 0.1:
            median = nums[left_position]
        else:
            median = float(nums[left_position] + nums[left_position + 1]) / 2

        length_from_start_to_median = left_position - start_pos

        return median, length_from_start_to_median
```
