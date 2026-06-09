![image.png](https://pic.leetcode-cn.com/6be06608da572c46d2821f51f2b6e482c5915166570353fd86577601fd598eac-image.png)


```
from typing import List

class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.m = {id : price for id , price in zip(products, prices)}
        self.n = n
        self.discount = discount
        self.idx = 0

    def getBill(self, product: List[int], amount: List[int]) -> float:
        self.idx += 1

        sum = 0
        for p, cnt in zip(product, amount):
            sum += self.m[p] * cnt

        if self.idx % self.n == 0:
            sum -= sum * (self.discount/100)
        return sum

```
