    这道题应该是无法使用真正的二分法的，因为在这一段数组中，**元素大小不保证严格单调，所以我们无法根据中点值排除掉数组的某一半搜索区间**。所以最快的方法仍然是**O(n)**，我们最多想办法将时间复杂度稍微降低一点。详细见代码，我们可以根据当前值的大小，试着**跳跃性排除**数组中的一小段。

```
class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        if not nums:
            return -1

        n = len(nums)
        i = 0
        while i < n:
            if nums[i] == i:
                return i
            if nums[i] > i: # 此时我们可以排除索引i到nums[i-1]这一整段
                i = nums[i] # 由于数组可以保持平稳，所以nums[i]这一元素不可排除
            else:
                i += 1
                
        return -1
```
