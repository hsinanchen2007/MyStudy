### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        left = 0
        right = len(nums)-1
        if right < 1:
            return nums
        while left < right:
            while left < right and nums[right] >= nums[left]:
                right -= 1
            if left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
            while left < right and nums[right] >= nums[left]:
                left += 1
            if left < right:
                nums[left], nums[right] = nums[right], nums[left]
                right -= 1
        return self.sortArray(nums[:left])+[nums[left]]+self.sortArray(nums[left+1:])
```


```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        dic = {i:0 for i in range(-50000, 50001)}
        for i in nums:
            dic[i] += 1
        res = []
        for i in dic:
            if dic[i] == 0:
                continue
            else:
                res += [i]*dic[i]
        return res
```