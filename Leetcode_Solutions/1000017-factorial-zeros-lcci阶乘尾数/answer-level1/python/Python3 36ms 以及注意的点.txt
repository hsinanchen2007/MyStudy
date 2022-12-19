这个题真的，数5就行了，**但是要注意是数因子的数量，不能五个五个数距离， 那样25， 125等等数字会少数**
```python
class Solution:
    def trailingZeroes(self, n: int) -> int:
        result = 0
        while(n > 0):
            result += n // 5
            n //= 5
        return result
```
