![2a00e7f7994b6baa12dc98f41943a55.png](https://pic.leetcode-cn.com/fcd02f938bc9667db5946b77b106e3d17ddc9d0e0a8ba28f36f5582ec77ac8c0-2a00e7f7994b6baa12dc98f41943a55.png)

```python []
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <= 0:  ## 如果num非正，就不是丑数
            return False
        while True:
            last = num
            if not num % 2:  ## 如果2整除num，就除以2
                num >>= 1
            if not num % 3:  ## 如果3整除num，就除以3
                num //= 3
            if not num % 5:  ## 如果5整除num，就除以5
                num //= 5
            if num == 1:  ## 如果若干次操作后，num变成1，说明num的因数只有2、3、5，是丑数
                return True
            if last == num:  ## 如果1轮操作后，num没变，说明num不是丑数
                return False
```

