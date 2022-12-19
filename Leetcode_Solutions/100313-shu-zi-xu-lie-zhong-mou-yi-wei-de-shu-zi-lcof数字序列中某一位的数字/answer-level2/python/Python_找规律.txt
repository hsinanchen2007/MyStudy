### 解题思路
一位数占 `9` 个位置
两位数占 `90*2` 个位置
三位数占 `900*3` 个位置
......
所以当 `n<=9` 时, 第 n 个位置是一位数
当 `9 < n <= 9 + 90*2` 时, 第 n 个位置是两位数
当 `9 + 90*2 < n <= 9 + 90*2 + 900*3` 时, 第 n 个位置是三位数
......
时间复杂度 O(log(n))
### 代码

```python3
class Solution:
    def findNthDigit(self, n: int) -> int:
        if n < 10:
            return n
        b, a, i = n, 9, 1
        while b > 0:
            b -= a * i
            a *= 10
            i += 1
        b += (a//10)*(i-1)
        x, y = b//(i-1), b%(i-1)
        if y == 0:
            c = pow(10, i-2) + x -1
            return int(str(c)[-1])
        else:
            c = pow(10, i-2) + x
            return int(str(c)[y-1])
```