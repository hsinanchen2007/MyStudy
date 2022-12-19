
```python []

def phi(n):
    rea = n
    for a in range(int(n ** 0.5)):
        if a > 0:
            i = a + 1
            if n % i == 0:
                rea = rea - rea / i
                while n % i == 0:
                    n /= i
    if n > 1:
        rea = rea - rea / n
    return rea


class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        B = 0
        b.reverse()
        n = 1
        for i in range(len(b)):
            B += b[i] * n
            n = n * 10

        return (a ** (B % phi(1337) + phi(1337))) % 1337
```
