### 解题思路
此处撰写解题思路

### 代码

```python3
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        left, right, mid = 1, n, (1+n) // 2
        tmp = guess(mid)
        while tmp:
            if tmp == -1:
                right = mid-1
                # mid = left + (right - left) // 2
                mid = (left + right) // 2
                tmp = guess(mid)
            else:
                left = mid + 1
                # mid = left + (right-left) //2
                mid = (left + right) // 2
                tmp = guess(mid)
        return mid

        # def helper(left, right):
        #     mid = (left + right) // 2
        #     if guess(mid) == 0:
        #         return mid 
        #     elif guess(mid) == -1:
        #         # right = mid - 1
        #         return self.helper(left, mid - 1)
        #     elif guess(mid) == 1:
        #         # left = mid + 1
        #         return self.helper(mid + 1, right)

        # res = helper(0, n)
        # return res




```