![image.png](https://pic.leetcode-cn.com/b1be72868b282b2d72742d87b06cfcb3f6f327c00c4ff882c88d8867ca3236ea-image.png)

唔，我挺怕这种题的，但是写多了有了一点找边界的感觉，写出来交流一下，先上代码。

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return -1, -1

        left_bound = self._search_left(nums, target)
        if left_bound != -1:
            return left_bound, self._search_right(nums, target)
        else:
            return -1, -1
    
    def _search_left(self, nums, target):
        l, r = 0, len(nums) - 1
        while l < r:
            m = l + (r - l) // 2

            if nums[m] < target:
                l = m + 1
            else:
                r = m
        
        return -1 if nums[l] != target else l

    def _search_right(self, nums, target):
        l, r = 0, len(nums) - 1
        while l < r:
            m = l + (r - l) // 2

            if nums[m] > target:
                r = m
            else:
                l = m + 1

        if nums[l] == target:
            return l

        if l != 0 and nums[l - 1] == target:
            return l - 1

        return -1
```
思路上来说就是搜两次，分别找下边界和上边界。从代码思维上来看，除了结尾的条件判断，其实主题部分都挺类似的，但是二者的边界有所不同。
```python
# 先看看没有迭代部分
# 搜索下边界
    def _search_left(self, nums, target):
        l, r = 0, len(nums) - 1
        while l < r:
            m = l + (r - l) // 2

            if nums[m] < target:
                l = m + 1
            else:
                r = m
        # 当左中位数元素m，比target要小时，说明m在target的左侧，因此l可以放心的往m右边踏一步
        # 而且不用担心超出找不到的问题，因为最差也是l刚好踏上target的左边界。
        # 当nums[m] >= target时，说明m在target的右边或者在target里面，这时候r不能往m的左边踏一步，也就是r = m - 1
        # 因为最差情况m可能刚好在target的左边界，如果r=m-1，可能直接就错过左边界了

# 搜索上边界
    def _search_right(self, nums, target):
    l, r = 0, len(nums) - 1
    while l < r:
        m = l + (r - l) // 2

        if nums[m] > target:
            r = m
        else:
            l = m + 1
    # 这里的分析和上面类似，如果m刚好在target右边，那么r=m，不能让r往m的左边走，也就是r=m-1，因为最差情况下，m在target的上边界
    # 如果r=m-1，那么r就会直接错过上边界，因为二分搜索中，无法让r看到自己身后的元素（当然也可以特殊考虑）。但是l就不用担心，
    # 因为最差情况下，l也就刚好踏到上边界，正好是我们要的结果。
```

上面是上下边界的搜索比较通用的部分，然后是特殊情况的考虑。
1. 下边界
    下边界的搜索有一个问题，那就是要处理找不到的情况，所以简单的判断下nums[l] == target就好了。

2. 上边界
    上边界相对复杂，因为通过上面的代码，搜出来的结果实际上分两种情况，一种是上边界不在数组尾，这样r就会停在上边界的右边一个元素，直接返回r-1就好了。但是还有一类情况是，上边界在数组尾上，那么就要一次额外的判断了。

以上就是本人对这道题的一个解题流程，欢迎指正。