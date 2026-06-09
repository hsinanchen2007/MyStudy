### 解题思路
本题易错点在于二分搜索结束后的索引结果需要再进行一次判断才能找到最终结果。
1. 二分查找mid取左中位数，相应的（为了确保不会陷入死循环），二分后，左边界为mid+1，右边界为mid。这种写法最后得到的索引一定是右边界（因为右边界不从mid收缩）。
2. 根据我们的判断条件，右边界是大于等于其本身索引的数。所以，最后需要判断一下，是大于还是等于。

例如：[0,1,2,3,4], 缺失的数字是5， 二分后指针落在数字4上, 所以return nums[r]+1
例如：[0,1,2,3,5], 缺失的数字是4， 二分后指针落在数字5上, 所以return nums[r]-1

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        l,r = 0,len(nums)-1
        while l<r:
            mid = l+(r-l)//2
            if nums[mid]==mid:
                l = mid + 1
            else:
                r = mid
        return nums[r]-1 if nums[r]>r else nums[r]+1


```