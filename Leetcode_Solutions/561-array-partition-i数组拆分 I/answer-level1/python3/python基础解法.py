解题思路：题目给定的是min（ai， bi）最小的话，这样其实每个ai最小其实就能满足了。类似于[1,4,3,2,5,6] -----> [(1,2), (3,4), (5,6)]，这样的话问题就能演变成排序，然后求偶数位的和。
代码：
```
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        count = 0
        for x,y in enumerate(sorted(nums)):
            if x % 2 == 0:
                count += y
        return count

```
