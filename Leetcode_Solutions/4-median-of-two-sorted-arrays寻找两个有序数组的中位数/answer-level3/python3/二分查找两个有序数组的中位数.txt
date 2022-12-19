#思路
时间复杂度为O(log(m+n))，自然想到使用「二分查找」来解决。

假设两个有序数组中的中位数是x，那么在两个数组中，有mid1和mid2将两个数组拆分成两部分，前半部分小于x，后半部分大于x，这样找到x后，mid1左侧和mid2左侧的数都应该比mid1和mid2对应的数小。

## 中位数
两个数组合并后长度为奇数，中位数是第(len(nums1) + len(nums2) + 1) // 2个数，
如果是偶数，中位数是第(len(nums1) + len(nums2) + 1) // 2和第(len(nums1) + len(nums2) + 1) // 2+1个数的平均值。

方便起见，假定第一个序列的长度不大于第二个，这样子，中位数不会出现在第二个数列的后半部分，即nums2[(len(nums1) + len(nums2) + 1) // 2:]。

首先先对第一个序列二分查找，记录左边界，右边界为第一个序列的左右边界，mid1 = (left + right) // 2。
mid2 = (len1 + len2 + 1) // 2-mid1

如果mid2左侧的数比mid1对应的都大，那不如第二行的数选小一点而第一行的数选大一点，这样两个数会更接近。要把第一行的中间往右，即二分查找的更新left，反之更新right。

##返回值
找到了第一行的中间数和第二行的中间数。
如果总数是奇数，那么输出左大，如果是偶数，输出左大和右小的平均数。
```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l1, l2 = len(nums1), len(nums2)
        if l1 > l2:
            l1, l2, nums1, nums2 = l2, l1, nums2, nums1
        left, right, halfLen = 0, l1, (l1 + l2 + 1) // 2
        mid1 = (left + right) // 2
        mid2 = halfLen - mid1

        while left < right:
            if mid1 < l1 and nums2[mid2 - 1] > nums1[mid1]:
                left = mid1 + 1
            else:
                right = mid1
            mid1 = (left + right) // 2
            mid2 = halfLen - mid1
        
        if mid1 == 0:
            maxLeft = nums2[mid2-1]
        elif mid2 == 0:
            maxLeft = nums1[mid1-1]
        else:
            maxLeft = max(nums1[mid1-1], nums2[mid2-1])
        
        if (l1 + l2) % 2 == 1:
            return maxLeft

        if mid1 == l1:
            minRight = nums2[mid2]
        elif mid2 == l2:
            minRight = nums1[mid1]
        else:
            minRight = min(nums1[mid1], nums2[mid2])

        return (maxLeft + minRight) / 2 
```
