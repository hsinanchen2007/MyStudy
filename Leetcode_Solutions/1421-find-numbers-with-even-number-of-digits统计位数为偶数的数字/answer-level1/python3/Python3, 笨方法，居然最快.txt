### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            tmp = 1
            while num > 9:
                num //= 10
                tmp += 1
            if tmp % 2 == 0:
                ans += 1
        return ans

```