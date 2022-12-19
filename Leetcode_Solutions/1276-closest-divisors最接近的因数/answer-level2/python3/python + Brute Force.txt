```python
class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        # a, b => a * b == num + 1 or a * b == num + 2
        def getFactors(num):
            sqrt = int(math.sqrt(num) + 1)
            for i in range(sqrt, 0, -1):
                if num % i == 0:
                    return (i, num // i)
        a1, b1 = getFactors(num + 1)
        a2, b2 = getFactors(num + 2)
        if abs(a1 - b1) < abs(a2 - b2):
            return [a1, b1]
        else:
            return [a2, b2]
```