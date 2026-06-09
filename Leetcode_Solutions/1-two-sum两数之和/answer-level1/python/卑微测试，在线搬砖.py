### 解题思路
遍历所有的积合，如果相等则返回

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lists = []
        for i in range(0, len(nums)):
            for j in range(i+1, len(nums)):
                if (nums[i]+nums[j]) == target:
                    lists.append(i)
                    lists.append(j)
        return lists
```