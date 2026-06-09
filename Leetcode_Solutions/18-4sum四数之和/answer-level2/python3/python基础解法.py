### 解题思路
思路和三数之和基本一致。先排序，后双指针，然后根据条件优化剪枝。

### 代码

```python3
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        result = []
        f = 0 # f, s, i, j
        while f < n - 3:  # 文中提到的两个条件，可以直接跳过
            if nums[f] + 3 * nums[f + 1] > target: break  
            if nums[f] + 3 * nums[-1] < target:           
                while f < n - 4 and nums[f] == nums[f + 1]: f += 1
                f += 1
                continue
            s = f + 1
            while s < n - 2:   # k 和 p 的判断是一样的
                if nums[f] + nums[s] + 2 * nums[s + 1] > target: break
                if nums[f] + nums[s] + 2 * nums[-1] < target: 
                    while s < n - 3 and nums[s] == nums[s + 1]:
                        s += 1
                    s += 1
                    continue
                i = s + 1
                j = n - 1
                new_target = target - nums[f] - nums[s]
                while i < j:
                    if nums[i] + nums[j] > new_target: j -= 1
                    elif nums[i] + nums[j] < new_target: i += 1
                    else:
                        res.append([nums[f],nums[s],nums[i],nums[j]])
                        i += 1
                        j -= 1
                        while i < j and nums[i] == nums[i - 1]: i += 1 # 避免结果重复
                        while i < j and nums[j] == nums[j + 1]: j -= 1 # 避免结果重复
                while s < n - 3 and nums[s] == nums[s + 1]: s += 1
                s += 1
            while f < n - 4 and nums[f] == nums[f + 1]: f += 1
            f += 1
        return result
```