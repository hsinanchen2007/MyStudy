方法一：
```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2)
        nums1.sort()
        if len(nums1)%2==0:
            n = len(nums1)
            n = int(n/2)
            s = n+1`
            mid = (nums1[n-1]+nums1[s-1])/2
            return mid
        elif len(nums1)%2!=0:
            s = int((len(nums1)+1)/2-1)
            mid = nums1[s]
            return mid

```


这个是比较通用的想法，先进行排序，再找中位数。

方法二：
  在前面排完序的基础上直接使用原有的库函数statistics.median直接就找到中位数。
  statistics中还有mean，mode分别代表均值和众数。
