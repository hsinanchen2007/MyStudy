解题思路：这个题比较饶，其实就是奇数到奇数，偶数到偶数都是代价为0，这样的话，可以将所有的奇数想为1，偶数想为0。看奇数和偶数的个数谁少答案就是谁。
代码：
```
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        even, odd = 0, 0
        for _, i in enumerate(chips):
            if i % 2 == 0:
                even += 1
            else:
                odd += 1
        return min(even, odd)
```
