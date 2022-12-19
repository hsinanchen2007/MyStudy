对整数分奇偶数的处理，可以看成计算整数二级制形式中1和0的数量统计，末尾为0及是偶数，一次操作，而位数为1时，减1操作后便是偶数了又可以直接偶数处理，所以可以看做一次处理记两次操作
处理：循环右移num，末尾为0操作+1，为1则+2(注意最左端的1只需要减1就是0了，所以需要结尾-1操作数)

```python 3
class Solution:
    def numberOfSteps (self, num: int) -> int:
        res = 0
        while num > 0:
            if num & 1:
                res += 2
            else:
                res += 1
            num >>= 1
        return res-1 if res > 0 else 0
```


