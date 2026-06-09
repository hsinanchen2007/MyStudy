### 解题思路
我觉得这个题可能是想考察数组合成排序，可是这个地方我直接用了extend函数和sort函数，结果执行用时直接击败了90.81%的用户，内存消耗直接击败了99.43%的用户，说明人家自带的函数实现的就是好，这个算作弊吗。。。

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2)
        nums1.sort()
        if len(nums1)%2:
            mid_num = int((len(nums1)-1)/2)
            return(nums1[mid_num])
        else:
            mid_num1 = int(len(nums1)/2)
            mid_num2 = mid_num1-1
            return((nums1[mid_num1]+nums1[mid_num2])/2)
```