### 解题思路
二分查找
* 二分查找标准解法，中间调用一次guess API比大小即可

### 代码

```python3
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        l,r = 1,n
        while l <= r:
            med = l + ( r - l ) // 2
            dst = guess(med)
            if dst == 1:
                l = med + 1
            elif dst == -1:
                r = med - 1
            else:
                return med
```