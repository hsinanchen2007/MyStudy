### 方法一：

依次二分查找每个对应的数，时间复杂度$O(NlogN)$

```python []
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for num in nums:
            if nums[bisect.bisect(nums, target - num) - 1] == target - num:
                return [num, target - num]
```

### 方法二：

二分查找到对应范围，然后双指针搜索答案，时间复杂度$O(N)$

```python []
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        j = bisect.bisect(nums, target) - 1
        for i in range(j):
            while nums[i] + nums[j] > target:
                print(i, j)
                j -= 1
            if nums[i] + nums[j] == target:
                return [nums[i], nums[j]]
```

