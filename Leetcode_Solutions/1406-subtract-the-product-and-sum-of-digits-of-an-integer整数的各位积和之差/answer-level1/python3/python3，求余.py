### 解题思路
没啥特别的

### 代码

```python3
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        sums , product = 0 , 1
        while n > 0:
            sums += n%10
            product *= n%10
            n //= 10
        return product - sums

```