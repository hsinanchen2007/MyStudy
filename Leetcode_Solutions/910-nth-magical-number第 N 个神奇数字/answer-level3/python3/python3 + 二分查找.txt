### 解题思路
使用二分查找搜索[min(A,B),N * B]范围，每个数的神奇数字个数 = mid 整除 A + mid 整除 B - mid 整除 AB最小公倍数.
类似题目：[https://leetcode-cn.com/problems/ugly-number-iii/]()

### 代码

```python3
class Solution:
    def nthMagicalNumber(self, N: int, A: int, B: int) -> int:
        ab = self.LCM(A, B)
        left = min(A, B)
        right = N * B
        while left < right:
            mid = (right + left) >> 1
            count = mid // A + mid // B - mid // ab
            if count < N:
                left = mid + 1
            else:
                right = mid
        return left % (10 ** 9 + 7)

    def LCM(self, a, b):
        """
        最小公倍数
        :param a:
        :param b:
        :return:
        """
        return a * (b // math.gcd(a, b))
```