```python
class StockSpanner:

    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        if not self.stack or price < self.stack[-1][0]:
            self.stack.append((price, 1))
        else:
            tempCnt = 1
            while self.stack and price >= self.stack[-1][0]:
                topVal, topCnt = self.stack.pop()
                tempCnt += topCnt
            self.stack.append((price, tempCnt))
        return self.stack[-1][1]

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
```