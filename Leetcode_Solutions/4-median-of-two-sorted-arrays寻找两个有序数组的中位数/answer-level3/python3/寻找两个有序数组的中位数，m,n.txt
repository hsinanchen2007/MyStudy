### 解题思路
之前做过寻找两个等长的有序数组的中位数，但是对于这个m,n的却一直没有一个完整的思路，因此借鉴了力扣给出的官方思想，这个题很有数学的味道。
1.中位数的作用就是
  I将一个集合划分为两个几乎等长(m+n为偶长度相等，否则可使前一个集合中元素的个数比后一个集合中元素的个数多一个)的集合
  II前面那个集合的最大数保证小于等于后面那个集合的最小数。
  形象点：
  left_part      right_part
  A[0]...A[i-1]  A[i]...A[m-1]
  B[0]...B[j-1]  B[j]...B[n-1]
  得到数学公式：
  i + j = m - i + n - j 或者 i + j = m - i + n - j + 1 即 i + j = int( (m+n+1)/2 )
  max( A[i-1], B[j-1] ) <= min( A[i], B[j] ) 即A[i-1] <= B[j] B[j-1] <= A[i]
  由公式IIA[i-1] <= B[j] B[j-1] <= A[i]可以筛选出i的值
  由公式I即可得到j的值
  至于中位数的值：
  m + n 为偶时，中位数等于 ( max(A[i-1], B[j-1]) + min(A[i], B[j]) )/2
  m + n 为奇时，中位数等于 max(A[i-1], B[j-1])
  PS:以上未考虑边缘情况
2.i位置的查找
  公式IIA[i-1] <= B[j] && B[j-1] <= A[i]
  我推理出遍历到不合适的i值时存在两种情况
  I.A[i-1] > B[j] && B[j-1] <= A[i],此时遍历指针可以向前寻找
  II.A[i-1] <= B[j] && B[j-1] > A[i],此时遍历指针可以向后寻找
  因此可使用low,high,mid的二分搜索法，不过在测试的过程中发现有些A指针的位置可能导致B元素指针出域，代码里有处理。
3.这只是普通情况，要考虑一些特殊情况，有一下几类。
  I一个数组是空数组另一个不是
  II一个数组被分到了left_part中，另一个数组被分到了right_part中
  IV一个数组只被分到了left_part中，未被分到right_part中
  V一个数组只被分到了right_part中，未被分到left_part中
4.代码做了一些if,else逻辑上的排列，可能可读性会降低。
总之这个题还是很细节的。
我参考了力扣官方的大致思想，主要是普通部分的思想，边缘是我自己设计的，主要是不想看了（偷懒）。
  

  


### 代码

```python3
from typing import List

class Solution:
    def oneIsEmpty(self,nums,isEven,reference):
        left = nums[reference - 1]
        if isEven:
            return (left + nums[reference]) / 2
        else:
            return left

    def half(self,nums1,nums2,isEven):
        m = len(nums1)
        left = nums1[m-1]
        if isEven:
            return ( left + nums2[0] )/2
        else:
            return left

    def leftNoAOrB(self,nums1,nums2,isEven,reference):
        left = nums2[reference - 1]
        if isEven:
            return (left + min(nums1[0], nums2[reference])) / 2
        else:
            return left

    def rightNoAOrB(self,nums1,nums2,isEven,reference):
        m = len(nums1)
        left = max(nums1[m - 1], nums2[reference - 1])
        if isEven:
            return (left + nums2[reference]) / 2
        else:
            return left

    def commonSituation(self,nums1,nums2,isEven):
        # 寻找i
        # 找到的情况
        # A[i-1] <= B[k] && A[i] >= B[k-1]
        # 2种反面情况
        # 1. A[i-1] > B[k] && A[i] >= B[k-1] 此时指针应当向前
        # 2. A[i-1] <= B[k] && A[i] < B[k-1] 此时指针应当向后
        m = len(nums1)
        n = len(nums2)
        reference = int( (m+n+1)/2 )

        low = 1
        high = m - 1
        while low <= high and low >= 1 and high <= m - 1:
            mid = int((low + high) / 2)
            k = reference - mid
            if k > n - 1:
                low += 1
            elif nums1[mid - 1] <= nums2[k] and nums1[mid] >= nums2[k - 1]:
                # 1.m+n为偶数 中位数 = ( max(A[i-1],B[j-1]) + min(A[i],B[j]) )/2
                # 2.m+n为奇数 中位数 = max(A[i-1],B[j-1] )
                left = max(nums1[mid - 1], nums2[k - 1])
                if isEven:
                    return (left + min(nums1[mid], nums2[k])) / 2
                else:
                    return left
            # 指针向前寻找
            elif nums1[mid - 1] > nums2[k] and nums1[mid] >= nums2[k - 1]:
                high = mid-1
            # 指针向后寻找
            elif nums1[mid - 1] <= nums2[k] and nums1[mid] < nums2[k - 1]:
                low = mid+1

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        reference = int( (m+n+1)/2 )
        reference_2 = int((abs(m-n) + 1) / 2)
        # m+n 是否为偶
        isEven = True
        if ( (m+n)%2 ) != 0 :
            isEven = False

        if m*n == 0:
            if m == 0 and n != 0:
                return self.oneIsEmpty(nums2,isEven,reference)
            if n == 0 and m != 0:
                return self.oneIsEmpty(nums1, isEven, reference)

        if m == n:
            if nums1[m-1] <= nums2[0]:
                return self.half(nums1, nums2, isEven)
            elif nums2[n-1] <= nums1[0]:
                return self.half(nums2, nums1, isEven)
            else:
                return self.commonSituation(nums1,nums2,isEven)

        if abs(m-n) == 1:
            if m > n and nums1[m-1] <= nums2[0]:
                return self.half(nums1, nums2, isEven)
            if m < n and nums2[n-1] <= nums1[0]:
                return self.half(nums2, nums1, isEven)

        if m < n:
            if nums2[reference -1] <= nums1[0]:
                return self.leftNoAOrB(nums1,nums2,isEven,reference)
            elif nums1[m -1] <= nums2[reference_2]:
                return self.rightNoAOrB(nums1, nums2, isEven, reference_2)
            else:
                return self.commonSituation(nums1, nums2, isEven)

        if m > n:
            if nums1[reference - 1] <= nums2[0]:
                return self.leftNoAOrB(nums2, nums1, isEven, reference)
            elif nums2[n - 1] <= nums1[reference_2]:
                return self.rightNoAOrB(nums2, nums1, isEven, reference_2)
            else:
                return self.commonSituation(nums2, nums1, isEven)
```