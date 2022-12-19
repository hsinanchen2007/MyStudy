### 解题思路
估计是因为题解还不够多的原因。

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            tmp = 0
            while num:
                num //= 10
                tmp += 1
            if tmp % 2 == 0:
                ans += 1
        return ans

```