### 解题思路
数字m每出现一次就将（m-1）索引处的数组值减去n，遍历一遍后与-n作比较，小于-n的数组值，其索引加1即为重复数字。

### 代码

```python3
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n):
            index = n * (nums[i] <= 0) + nums[i] - 1
            nums[index] -= n
        ans = []
        for i in range(n):
            if nums[i] <= -n:
                ans.append(i+1)
        return ans
```