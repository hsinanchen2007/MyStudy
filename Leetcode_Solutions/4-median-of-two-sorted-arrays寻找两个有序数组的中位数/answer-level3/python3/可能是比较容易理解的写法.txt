看别人的实在看不懂，自己也是新手，琢磨了很久明白是把数组分成左右两堆的过程，最后循环退出的条件是这次的分割方式满足条件：左堆的最大值小于右堆的最小值。split_1 表示第一堆有多少个放到左堆。
```
class Solution(object):
    def findMedianSortedArrays(self, nums1: List[int],
                               nums2: List[int]) -> float:
        if len(nums1) == 0:
            nums1 = nums2
        if len(nums2) == 0:
            nums2 = nums1
        nums1.insert(0, min(nums1[0], nums2[0]))
        nums2.insert(0, min(nums1[0], nums2[0]))
        nums1.append(max(nums1[-1], nums2[-1]))
        nums2.append(max(nums1[-1], nums2[-1]))
        m = len(nums1)
        n = len(nums2)
        # 让nums2成为更长的那一个数组
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m

        half_length = (m + n) // 2
        # 在较短序列上选择一个分界点，左边的都放到左堆中
        left_range = 0
        right_range = m
        split_1 = (left_range + right_range) // 2
        split_2 = half_length - split_1

        while left_range < right_range:
            if nums1[split_1] < nums2[split_2 - 1]:
                left_range = split_1 + 1
            elif nums1[split_1 - 1] > nums2[split_2]:
                right_range = split_1
            else:
                break
            split_1 = (left_range + right_range) // 2
            split_2 = half_length - split_1

        if (m + n) % 2 == 0:
            if split_1 == 0:
                max_left = nums2[split_2 - 1]
            elif split_2 == 0:
                max_left = nums1[split_1 - 1]
            else:
                max_left = max(nums1[split_1 - 1], nums2[split_2 - 1])
            if split_1 == m:
                min_right = nums2[split_2]
            elif split_2 == n:
                min_right = nums1[split_1]
            else:
                min_right = min(nums1[split_1], nums2[split_2])
            return (max_left + min_right) / 2
        else:
            if split_1 == m:
                min_right = nums2[split_2]
            elif split_2 == n:
                min_right = nums1[split_1]
            else:
                min_right = min(nums1[split_1], nums2[split_2])
            return min_right
```
