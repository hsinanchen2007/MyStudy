### 解题思路
见题解: [69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/solution/cai-yong-pai-chu-fa-by-gelthin/)

### 代码

```python3
# The guess API is already defined for you.
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        left, right = 1, n
        while(left<right):
            mid = (left+right)//2
            if guess(mid) == 1:
                left = mid +1
            else:
                if guess(mid) == 0:
                    return mid
                right = mid-1
        return left
```