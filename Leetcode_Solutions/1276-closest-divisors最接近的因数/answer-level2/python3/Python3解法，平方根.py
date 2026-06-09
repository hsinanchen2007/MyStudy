从最接近的平方根开始遍历，最接近（或等于）平方根的一定是差值最小的两个因数。
质数只有1和自身两个因数。

```python3
def cloestFactor(num):
    sqrt = int(num**0.5)
    high = sqrt
    while high > 1:
        if num % high == 0:
            low = num // high
            return [low, high]
        high -= 1
    return [1, num]

class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        low1, high1 = cloestFactor(num + 1)
        low2, high2 = cloestFactor(num + 2)
        return [low1, high1] if abs(low1-high1) < abs(low2-high2) else [low2, high2]     
```
