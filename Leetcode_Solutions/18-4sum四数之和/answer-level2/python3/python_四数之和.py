### 解题思路
三指针法：
和三数之和思路一模一样，未来的五六七数之和也是一样

### 代码

```python3
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        if not nums or len(nums) < 4:
            return result
        nums.sort()
        length = len(nums)
        for k in range(length - 3):
            if k > 0 and nums[k] == nums[k - 1]:
                continue
            min1 = nums[k] + nums[k+1] + nums[k+2] + nums[k+3]
            if min1 > target:
                break
            max1 = nums[k] + nums [length-1] + nums[length - 2] + nums[length - 3]
            if max1 < target:
                continue
            for i in range(k+1, length-2):
                if i > k + 1 and nums[i] == nums[i - 1]:
                    continue
                j = i + 1
                h = length - 1
                min2 = nums[k] + nums[i] + nums[j] + nums[j + 1]
                if min2 > target:
                    continue
                max2 = nums[k] + nums[i] + nums[h] + nums[h - 1]
                if max2 < target:
                    continue
                while j < h:
                    curr = nums[k] + nums[i] + nums[j] + nums[h]
                    if curr == target:
                        result.append([nums[k], nums[i], nums[j], nums[h]])
                        j += 1
                        while j < h and nums[j] == nums[j - 1]:
                            j += 1
                        h -= 1
                        while j < h and i < h and nums[h] == nums[h + 1]:
                            h -= 1
                    elif curr > target:
                        h -= 1
                    elif curr < target:
                        j += 1
        return result
```