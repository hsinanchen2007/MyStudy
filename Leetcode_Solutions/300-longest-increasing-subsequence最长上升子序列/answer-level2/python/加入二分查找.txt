### 解题思路
新建一个 low 数组，low [ i ]表示长度为i的LIS结尾元素的最小值。对于一个上升子序列，显然其结尾元素越小，越有利于在后面接其他的元素，也就越可能变得更长。因此，我们只需要维护 low 数组，对于每一个nums[ i ]，如果nums[ i ] > low [当前最长的LIS长度]，就把 nums[ i ]接到当前最长的LIS后面，即low [++当前最长的LIS长度] = nums [ i ]。 
那么，怎么维护 low 数组呢？
对于每一个nums [ i ]，如果nums [ i ]能接到 LIS 后面，就接上去；否则，就用 nums [ i ] 取更新 low 数组。具体方法是，在low数组中找到第一个大于等于nums[ i ]的元素low [ j ]，用nums [ i ]去更新 low [ j ]。如果从头到尾扫一遍 low 数组的话，时间复杂度仍是O(n^2)。我们注意到 low 数组内部一定是单调不降的，所有我们可以二分 low 数组，找出第一个大于等于nums[ i ]的元素。二分一次 low 数组的时间复杂度的O(lgn)，所以总的时间复杂度是O(nlogn)。

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        size = len(nums)
        if size<2:
            return size
        
        low = [nums[0]]
        for num in nums[1:]:
            if num>low[-1]:
                low.append(num)
                continue
            
            l,r = 0,len(low)-1
            while l<r:
                mid = l + (r - l) // 2
                if low[mid]<num:
                    l = mid + 1
                else:
                    r = mid
            low[l] = num
        return len(low)
```