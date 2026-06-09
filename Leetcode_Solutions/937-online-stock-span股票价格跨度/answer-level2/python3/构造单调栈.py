```
class StockSpanner(object):

    def __init__(self):
        self.stack = []

    def next(self, price):
        """
        :type price: int
        :rtype: int
        """
        num = 1
        while self.stack:
            n = self.stack[-1]
            if price < n[0]:
                break
            num += n[1]
            self.stack.pop()
        self.stack.append([price, num])
        return num       
```
