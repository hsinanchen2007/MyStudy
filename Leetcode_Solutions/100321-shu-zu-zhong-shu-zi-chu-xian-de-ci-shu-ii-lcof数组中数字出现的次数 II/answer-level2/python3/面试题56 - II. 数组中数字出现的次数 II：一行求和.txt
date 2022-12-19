### 解题思路
没有空间限制直接求和便是，时间$O(N)$，临时空间$O(N)$。

### 代码

```python []
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return (3 * sum({*nums}) - sum(nums)) // 2
```


### 解题思路
排序法，时间$O(NlogN)$，空间$O(1)$。

### 代码

```python []
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        return next((nums[i] for i in range(len(nums) - 1) if nums[i] not in (nums[i - 1], nums[i + 1])), nums[-1])
```
