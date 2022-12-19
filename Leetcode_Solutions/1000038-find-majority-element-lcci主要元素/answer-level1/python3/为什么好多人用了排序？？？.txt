### 解题思路
执行用时 :
44 ms
, 在所有 Python3 提交中击败了
92.11%
的用户
内存消耗 :
15.1 MB
, 在所有 Python3 提交中击败了
100.00%
的用户

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        halflength = len(nums) / 2
        for i in set(nums):
            if nums.count(i) > halflength:
                return i
        return -1
```