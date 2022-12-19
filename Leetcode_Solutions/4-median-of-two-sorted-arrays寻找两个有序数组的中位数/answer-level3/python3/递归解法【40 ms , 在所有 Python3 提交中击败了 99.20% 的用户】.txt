### 解题思路
一看到这个题就想着用递归做，然后就出不来了。
一开始是想两个列表同砍一半，再弄个偏移量记录偏移情况的。后面还是按左右同缩的思路来做，即短的砍一半，长的按同数量缩减，保证中位数一直在剩下的列表里不丢失；尤其是不要在砍一半的时候，把可能是偶列表中位数的其中一个砍丢了。
为叙述方便，长度为偶数的列表称偶列表，长度为奇数的称奇列表。具体思路：
1、通过调换，使得nums1始终是砍多少的数量基准。
2、当第一个列表长度为空，则直接取第二个数据的中位数。
3、当第一个列表长度为1。当第二个数组为偶列表时，中位数只会nums1[mid1]、nums2[mid2-1]、nums2[mid2]三个数中间选一个。当第二个数据为奇列表时，中位数只会在nums1[mid1]与第二个数组的中间三个数两两组合而成。
4、当第一个列表是偶列表。当第二个列表为偶列表时，如果nums1的两个中位数跟nums2的两个中位数不相交，则直接按nums1的一半砍即可；如果相交，则必定在两组中位数中间组合而成。当第二个列表为奇列表时，如果nums1的两个中位数跟nums2中间的三个数不相交，则直接按nums1的一半砍即可；如果相交，则只会在nums1的两个中位数以及nums2[mid2]这三个数中间选一个。
5、当第一个列表是奇列表。要么左边砍一半，要么右边砍一半，始终保证nums1[mid1]不丢，就行了。

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        len1,len2 = len(nums1),len(nums2)
        mid1,mid2 = len1//2,len2//2
        if len1 > len2:
            nums1,nums2 = nums2,nums1
            len1,len2 = len2,len1
            mid1,mid2 = mid2,mid1
        if len1 == 0:
            if mid2 * 2 == len2:
                return (nums2[mid2] + nums2[mid2-1])/2
            else:
                return nums2[mid2]
        elif len1 == 1:
            if len2 == 1:
                return (nums1[mid1]+nums2[mid2])/2
            elif mid2 * 2 == len2:
                if nums2[mid2] <= nums1[mid1]:
                    return nums2[mid2]
                elif nums2[mid2-1] >= nums1[mid1]:
                    return nums2[mid2-1]
                else:
                    return nums1[mid1]
            else:
                if nums2[mid2+1] <= nums1[mid1]:
                    return (nums2[mid2] + nums2[mid2+1])/2
                elif nums2[mid2-1] >= nums1[mid1]:
                    return (nums2[mid2] + nums2[mid2-1])/2
                else:
                    return (nums2[mid2] + nums1[mid1])/2
        if mid1 * 2 == len1:
            if mid2 * 2 == len2:
                if nums2[mid2] <= nums1[mid1-1]:
                    return self.findMedianSortedArrays(nums1[0:mid1],nums2[mid1:len2])
                elif nums2[mid2-1] >= nums1[mid1]:
                    return self.findMedianSortedArrays(nums1[mid1:len1],nums2[0:len2-mid1])
                else:
                    if nums2[mid2-1] <= nums1[mid1-1]:
                        if nums2[mid2] >= nums1[mid1]:
                            return (nums1[mid1-1]+nums1[mid1])/2
                        else:
                            return (nums1[mid1-1]+nums2[mid2])/2
                    else:
                        if nums2[mid2] >= nums1[mid1]:
                            return (nums2[mid2-1]+nums1[mid1])/2
                        else:
                            return (nums2[mid2-1]+nums2[mid2])/2
            else:
                if nums2[mid2+1] <= nums1[mid1-1]:
                    return self.findMedianSortedArrays(nums1[0:mid1],nums2[mid1:len2])
                elif nums2[mid2-1] >= nums1[mid1-1]:
                    return self.findMedianSortedArrays(nums1[mid1:len1],nums2[0:len2-mid1])
                else:
                    if nums2[mid2] >= nums1[mid1-1]:
                        if nums2[mid2] <= nums1[mid1]:
                            return nums2[mid2]
                        else:
                            return nums1[mid1]
                    else:
                        return nums1[mid1-1]
        else:    
            if nums1[mid1] < nums2[mid2]:
                return self.findMedianSortedArrays(nums1[mid1:len1],nums2[0:len2-mid1])
            else:
                return self.findMedianSortedArrays(nums1[0:mid1+1],nums2[mid1:len2])
```