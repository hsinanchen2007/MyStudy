### 解题思路
1. 解题目标：
- 一个数组中有0,1
- 1连续的最大长度
2. 解题思路：
- 遍历，遇0初始为0，记录

### 代码

```python3
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_len = 0
        temp_len = 0
        n = len(nums)
        for i in range(n):
            if nums[i] == 0:
                max_len = max(max_len,temp_len)
                temp_len = 0
            else:
                temp_len += 1
        return max(max_len,temp_len)



```