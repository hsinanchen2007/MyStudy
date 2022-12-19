说是一道算法题，但感觉是道阅读理解题。

初看题目比较懵逼，题目的意思是：

- 提供了一个预先定义好的接口 `guess(int num)`
- 这个接口回返回 3 个结果：
  1. `-1`：代表你猜测的数字大了
  2. `1`：代表你猜测的数字小了
  3. `0`：代表你猜对了 `( •̀ᄇ• ́)ﻭ✧`

本质就是一个在 `1 ~ n` 范围内查找某个特定数的过程，用二分来做。

```python
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        left = 1
        right = n
        while left <= right:
            mid = left + (right - left) // 2
            # 猜测结果
            flag = guess(mid)
            if flag == -1:
                # 猜大了
                right = mid - 1
            elif flag == 1:
                # 猜小了
                left = mid + 1
            else:
                # 猜对了
                return mid
```