**算法思路**，递归，比较两个数组中位数大小，截断中位数较小数组左边一部分，截断中位数较大数组右边一部分，截断长度为长度较小数组长度一半减去1（为了不切到算中位数的数），一直到较短数组长度等于2。这时候如果另一个数组长度很长，可以将另一个数组左右两边截断，最多截断到数组总长度为3或4。最后特殊情况，如果有输入是空，或者有输入长度是1，归到长度小于等于2一起算。
**时间复杂度**，每次递归两个数组都截断 ceil(min(m, n))/2 -1 的长度，直到较短数组长度为2，时间复杂度为O(log(min(m, n)))
**python3代码**：

```
class Solution:

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        n1 = len(nums1)
        n2 = len(nums2)
        if n1 > n2:
            return self.findMedianSortedArrays(nums2, nums1)

        if n1 <= 2:
            if n2 > 4:
                cut = math.ceil(n2 / 2) - 2
                nums2 = nums2[cut: -cut]
            nums = nums1 + nums2
            nums.sort()
            return self.findMedian(nums)

        cut = math.ceil(n1 / 2) - 1
        if self.findMedian(nums1) < self.findMedian(nums2):
            return self.findMedianSortedArrays(nums1[cut:], nums2[:-cut])
        else:
            return self.findMedianSortedArrays(nums1[:-cut], nums2[cut:])


    def findMedian(self, l: List[int]) -> float:
        return (l[len(l) // 2] + l[(len(l)-1) // 2]) / 2

```
