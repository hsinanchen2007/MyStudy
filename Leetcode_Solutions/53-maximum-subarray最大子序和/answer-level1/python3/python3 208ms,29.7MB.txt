### 解题思路
遍历一遍列表，逐个加起来，如果当前的值大就存到ans中，如果小于0就重新置0
总感觉这个方法有一点小问题，但是却通过了

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = -sys.maxsize - 1
        cur = 0
        for i in nums:
            cur += i
            if cur > ans:
                ans = cur
            if cur < 0:
                cur = 0
        return ans
```