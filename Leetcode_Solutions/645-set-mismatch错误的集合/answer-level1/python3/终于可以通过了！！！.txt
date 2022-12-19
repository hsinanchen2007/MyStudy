### 解题思路
链接：https://leetcode-cn.com/problems/set-mismatch/solution/645cuo-wu-de-ji-he-by-shi-nian-zhi-zhuo/

### 代码

```python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        out = [0] * 2
        count = [0] * 10002
        for i in range(len(nums)):
            count[nums[i]] += 1
        for i in range(len(nums)+1):
            if count[i] == 2:
                out[0] = i
            elif count[i] == 0 and i != 0 and i <= len(nums):
                out[1] = i
        return out
```