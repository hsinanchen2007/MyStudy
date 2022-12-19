### 解题思路
用一个hash map 来存储商品和价格的对应关系，这在之后计算bill查找价格的时候能节省时间。
### 代码

```python
class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.n, self.disc = n, discount
        self.dic = {}
        for i, v in enumerate(products):
            self.dic[v] = prices[i]
        self.n_customer = 0
        

    def getBill(self, product: List[int], amount: List[int]) -> float:
        self.n_customer +=1
        if self.n_customer == self.n:
            self.n_customer = 0
            disc = self.disc
        else:
            disc = 0
        bill = 0
        for i, prod in enumerate(product):
            bill += amount[i]*self.dic[prod]
        bill = bill*(1-disc/100)
        return bill
            


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
```