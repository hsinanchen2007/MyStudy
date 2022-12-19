### 解题思路
原数组所有数的和 - set(原数组)所有数的和 = 重复了的数值
1~n的和 - 原数组所有数的和 = 缺少的数值

### 代码

```python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        s = sum(set(nums))
        return [sum(nums)-s, sum(range(1,len(nums)+1))-s]
```