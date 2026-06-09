```
def pow(self, x, n):
    if n == 1 or n == -1:
        return x
    if n == 0:
        return 1
    a = 1
    b = x

    while a * 2 <= abs(n):
        a *= 2
        x = x * x

    return x * self.pow(b, abs(n) - a)


def myPow(self, x, n):
    a = self.pow(x, n)
    if n < 0:
        a = 1 / a
    return a
```
