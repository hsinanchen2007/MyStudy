### 解题思路
使用集合遍历。

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums = set(nums)   #这里选择使用集合set，而直接使用列表会超时。
        for i in nums:
            if target - i in nums: return [i, target - i] 
```