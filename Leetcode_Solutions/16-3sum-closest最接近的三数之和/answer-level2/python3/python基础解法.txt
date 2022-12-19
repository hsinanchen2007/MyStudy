### 解题思路
先排序，后双指针更新和差距最小的值，如果相等直接输出

### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        if len(nums) == 3:
            return sum(nums)
        mindiff = float('inf')
        nums.sort()
        for i in range(len(nums)):
            # 减少重复计算
            if i>0 and nums[i] == nums[i-1]:
                continue
            r, l = i+1, len(nums)-1
            while r<l:
                count = nums[i]+nums[r]+nums[l]
                if target == count:
                    return target
                if abs(count-target) < abs(mindiff-target):
                    mindiff = count
                if count-target < 0:
                    r += 1
                else:
                    l -= 1
        return mindiff

```