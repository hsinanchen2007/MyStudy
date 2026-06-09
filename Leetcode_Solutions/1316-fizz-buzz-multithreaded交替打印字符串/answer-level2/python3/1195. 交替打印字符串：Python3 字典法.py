设一个线程安全的全局字典`self.d`存储`4`个函数的函数指针，每次获取函数指针的时候进行判断是否获取完了全部函数指针，当满足数量条件时，按顺序输出指针的对应的函数项，这个方法可以解决目前LeetCode里面的所有的多线程问题。

```python []
class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.d = {}

    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        self.d['f'] = printFizz
        self.res()

    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        self.d['b'] = printBuzz
        self.res()

    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        self.d['fb'] = printFizzBuzz
        self.res()

    def number(self, printNumber: 'Callable[[int], None]') -> None:
        self.d['n'] = printNumber
        self.res()
    
    def res(self):
        if len(self.d) == 4:
            for i in range(1, self.n + 1):
                if i % 15 == 0:
                    self.d['fb']()
                elif i % 3 == 0:
                    self.d['f']()
                elif i % 5 == 0:
                    self.d['b']()
                else:
                    self.d['n'](i)
```

![image.png](https://pic.leetcode-cn.com/9d2a36e206715e39c8aa2443380380254de2e428ae41a2029eabdef203c20055-image.png)

56ms仅供参考。