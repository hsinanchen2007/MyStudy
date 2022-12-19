建立栈的时候（插入元素的时候），记录下每次出现连串1时的起始终止位置。（因为1不改变乘积值）

在乘积的时候，如果这个元素是1就去找是不是在 1栈 中，如果在，直接跳过这段1，再去比较键值是否超过 k。

用时 336 ms
空间 28 MB

```python
class ProductOfNumbers(object):

    def __init__(self):
        self.stack = []
        self.ones = []

    def add(self, num):
        self.stack.append(num)
        if num == 1:
            n = len(self.stack) - 1
            if not self.ones:
                self.ones.append([n, n])
            else:
                if n - 1 == self.ones[-1][-1]:
                    self.ones[-1][-1] = self.ones[-1][-1] + 1
                else:
                    self.ones.append([n, n]) 

    def getProduct(self, k):
        if k == 0:
            return 0
        pro = 1
        n = len(self.stack)
        i = n - 1
        key = -1
        while i >= n - k:
            temp = self.stack[i]
            if temp == 1:
                if self.ones[key][-1] == i:
                    i = self.ones[key][0]
                    key = key - 1
            pro = pro * temp
            if pro == 0:
                return 0
            i = i - 1
        return pro
```