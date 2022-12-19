执行用时 :44 ms, 在所有 Python3 提交中击败了99.74% 的用户。
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了95.04%的用户。

```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        s = sum(nums)
        n = len(nums)
        num = n*(n+1)//2 - s
        return num
```

当然，也可以一行搞定，不过运行会有点慢

```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return len(nums)*(len(nums)+1)//2 - sum(nums)
```

