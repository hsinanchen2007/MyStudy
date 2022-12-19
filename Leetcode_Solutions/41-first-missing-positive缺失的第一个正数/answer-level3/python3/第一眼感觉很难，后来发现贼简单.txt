### 解题思路
设len(nums) == n; 那么我们返回的结果肯定不会大于n+1; 例如 nums = [1, 2, 3] 则返回结果为4， 不会超过4；
因此我们可以从i = 1开始，判断i是否在nums数组中，如果不在就返回该数字，若在就将i+1再继续判断，如此循环下去，最多
我们循环n+1次，时间复杂度为O(n)

### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        i = 1
        while True:
            if i not in nums:
                return i
            i += 1
```