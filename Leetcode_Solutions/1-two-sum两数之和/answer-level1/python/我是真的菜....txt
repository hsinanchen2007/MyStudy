### 解题思路
简直了 赶紧胡弄完看人家的题解...

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            if target-nums[i] in nums:
                temp = target-nums[i]
                tempint = nums[i] #fail safe
                nums[i] = 'a'#占位保证index原样
                if temp in nums:
                    idx = nums.index(temp)
                    break
                else:
                    nums[i] = tempint
                    continue
        return [i,idx]
```