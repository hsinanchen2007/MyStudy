### 解题思路
此处撰写解题思路
采用滑动窗口解法
```javascript []
console.log('Hello world!')
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
### 代码

```python3
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        temp = []
        nums.sort()
        for idx1 in range(len(nums) - 3):
            if(nums[idx1] + nums[idx1 + 1] + nums[idx1 + 2] + nums[idx1 + 3]) > target:
                break
            if(nums[idx1] + nums[-3] + nums[-2] + nums[-1]) < target:
                continue
            for idx2 in range(idx1 + 1, len(nums) - 2):
                if(nums[idx1] + nums[idx2] * 3) > target:
                    break
                if(nums[idx1] + nums[idx2] + nums[-2] + nums[-1]) < target:
                    continue
                for idx3 in range(idx2 + 1, len(nums) - 1):
                    if(nums[idx1] + nums[idx2] + nums[idx3] * 2) > target:
                        break
                    if(nums[idx1] + nums[idx2] + nums[idx3] + nums[-1]) < target:
                        continue
                    for idx4 in range(idx3 + 1, len(nums)):
                        temp = [nums[idx1], nums[idx2], nums[idx3], nums[idx4]]
                        if(temp not in result) and (sum(temp) == target):
                            result += [temp]
        return result
                         

```