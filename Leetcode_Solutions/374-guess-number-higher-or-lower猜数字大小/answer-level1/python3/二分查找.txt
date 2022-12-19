### 解题思路
![image.png](https://pic.leetcode-cn.com/2efdeeffb0f43d61fe44a5285da24eef7c0d4df7184734b2e325273eda0bbad5-image.png)

### 代码

```python3
# The guess API is already defined for you.
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        l, r = 1, n
        while l <= r: # 必须是<=
            m = (l+r) // 2
            res = guess(m)
            if res == 0:
                return m
            elif res == -1:
                r = m - 1
            else:
                l = m + 1
        return None
```