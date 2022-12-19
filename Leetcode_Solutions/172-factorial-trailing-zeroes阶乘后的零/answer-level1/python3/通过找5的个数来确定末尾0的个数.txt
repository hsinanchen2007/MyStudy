末尾零的个数取决于5的倍数中包含的5的个数，如5,10都只包含一个5，而25包含两个，125包含3个，依次类推。有点投机取巧了，哈哈。


```
class Solution:
    def trailingZeroes(self, n: int) -> int:
        flag = 0
        for i in range(1, 100):
            if 5**i <= n:
                flag += n // 5**i
            else:
                break
        return flag
```