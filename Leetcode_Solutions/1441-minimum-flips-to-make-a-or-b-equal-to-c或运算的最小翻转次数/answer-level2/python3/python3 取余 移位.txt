### 解题思路
1.通过取余得到二进制的最后一位的数字
2.通过移位得到除2后的新值
3.循环之

### 代码

```python3
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        res = 0
        while a != 0 or b != 0 or c != 0:
            ra = a % 2
            rb = b % 2
            rc = c % 2
            a >>= 1
            b >>= 1
            c >>= 1
            if rc == 1:
                if ra == 0 and rb == 0:
                    res += 1
            if rc == 0:
                if ra != rb:
                    res += 1
                elif ra == 1:
                    res += 2
            #print(ra,rb,rc,a, b, c, res)
        return res
```