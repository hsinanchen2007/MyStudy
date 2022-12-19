```
class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        def quick(n, x):
            res = 1
            while(n):
                if(n&1):
                    res = res * x % 1337
                n >>= 1
                x = x * x % 1337
            return res
        result = 1
        while(b):
            e = b.pop()
            if(e):
                result = result * quick(e, a) % 1337
            a = quick(10, a)
        return result

```
