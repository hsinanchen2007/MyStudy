
## 解法一：每次调用next后将股票值存储起来，随后向前搜索
next 时间复杂度O(n)， n次next下总共的时间复杂度为O(n²)
空间复杂度 O(n)

## 解法二：规律（动态规划）
如果当前股票价格比昨天的低，那么跨度必定为1。
如果当前股票价格大于等于昨天价格，则可以利用此前的跨度跳跃的往前搜索。


时间复杂度分析：
如果当前股票价格比昨天的低，那么跨度为1，只需O(1)的时间复杂度
如果当前股票价格大于等于昨天价格，每次依赖于此前的跨度，最坏情况下为O(n)，但是普遍情况下只需要依赖前几个跳板即可完成。

看这个例子会清晰很多
```
s = StockSpanner()
s.next(90)  
s.next(80)
s.next(70)
s.next(60)
s.next(50)
s.next(100)

相应的跳板序列
[(90, 1)]   O(1)
[(90, 1), (80, 1)]  O(1)
[(90, 1), (80, 1), (70, 1)]     O(1)
[(90, 1), (80, 1), (70, 1), (60, 1)]    O(1)
[(90, 1), (80, 1), (70, 1), (60, 1), (50, 1)]   O(n)
next复杂度  (O(1) + O(1) + O(1) + O(n)) / n = O(1)
```

next 时间复杂度均摊下为 O(1)， 总体时间复杂度为O(n)
空间复杂度为两个数组 O(n)

代码如下：
```
class StockSpanner:

    def __init__(self):
        self.degree = 0
        self.prev = 1 << 31
        self.degrees = []
        self.stock = []

    def next(self, price: int) -> int:
        self.stock.append(price)

        if price < self.prev:
            self.degrees.append(1)
        else:
            d = 1
            j = len(self.stock) - 2
            while j >= 0 and self.stock[-1] >= self.stock[j]:
                d += self.degrees[j]
                j -= self.degrees[j]

            self.degrees.append(d)

        self.prev = price
        return self.degrees[-1]
```

## 解法三：单调栈
从规律中可以看出，优化时间复杂度的关键在于能否直接获取此前的跨度，并且还可以发现在利用跨度进行跳跃时，无需知道跳板之外的元素值，因此可以优化空间复杂度，即只保存跳板元素值和跳板的跨度。

举例来看，股票序列 [100, 80, 60, 70, 60, 75, 85]
对于75来说，跳板为 [(60, 1<跨度>), (70, 2<跨度>)]，如果还有跳板的话，那么跳板必然是会比70更大的，因此跳板的存储具有单调性。

对于85来说，跳板为 [(75, 4), (80, 1)]，其中(75, 4)是由此前的(75, 1),(60, 1), (70, 2)组合而成的，因此从结构上来说可以想到单调栈。

因此单调栈为单调递减栈，每个元素为<元素值，跨度>，每次调用一次next，就对应着单调栈的维护操作。

时间复杂度与解法二相同，为O(n)
空间复杂度为一个栈 O(n)

```
class StockSpanner:

    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        d = 1
        while len(self.stack) > 0 and price >= self.stack[-1][0]:
            d += self.stack.pop()[1]

        self.stack.append((price, d))
        return d
```