### 解题思路
1、判断在不在nums中，
2、在就返回index，不在就返回-1

### 代码

```python3

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            return -1

```