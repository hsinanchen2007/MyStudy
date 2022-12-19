### 解题思路
总共需要输出n个0和1~n的正整数，而且是先输出0再输出正整数，所以可以用零队列，奇数队列，偶数队列做控制

### 代码

```python3
import queue

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.count = 1
        self.zero_q = queue.Queue()
        self.even_q = queue.Queue()
        self.odd_q = queue.Queue()
        self.zero_q.put(0)

    # printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n):
            self.zero_q.get()
            printNumber(0)
            if self.count % 2:
                self.odd_q.put(0)
            else:
                self.even_q.put(0)

    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n//2):
            self.even_q.get()
            printNumber(self.count)
            self.count += 1
            self.zero_q.put(0)
            

    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(math.ceil(self.n/2)):
            self.odd_q.get()
            printNumber(self.count)
            self.count += 1
            self.zero_q.put(0)
```