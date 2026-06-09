

```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
         a = set(range(len(nums)+1))
         return (a-set(nums)).pop()
```

![捕1获.PNG](https://pic.leetcode-cn.com/2c1759a0cd499ca919d561ecb22cff0eda828b23d7ccf8d8a8c9f08594a4f8e1-%E6%8D%951%E8%8E%B7.PNG)

我这个小白很开心了，发完继续看大佬解法