应该比较好懂，就不做解释了
```
class Solution:
    def convertToBase7(self, num: int) -> str:
        def digui(num,a,f = 1):
            if num < 0:
                f = -1
            if num == 0:
                if f == 1:
                    return ''.join(reversed(a))
                else:
                    a += '-'
                    return ''.join(reversed(a))
            num = abs(num)
            b = str(num % 7)
            a += b
            return digui(num//7,a,f)
        if num == 0:
            return '0'
        return digui(num,'',f = 1)
```
