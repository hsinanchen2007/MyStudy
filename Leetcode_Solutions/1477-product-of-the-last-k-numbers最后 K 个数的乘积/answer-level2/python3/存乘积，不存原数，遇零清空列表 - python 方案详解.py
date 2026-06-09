### 方法

第一可能查询的次数很多，区间也可能很大，如果每次查询都现算可能超时。但是每个数字都不大。

这时候就考虑不存数字本身，而是存连乘后的结果。例如输入的 a b c d。则存的是 a，a×b，a×b×c，a×b×c×d。这样。如果查询最后两个数相乘，就是倒数第一除以倒数第三就是 （a×b×c×d）/ （a×b）= c × d。这样每次查询只需要做一次除法，每次输入只需要做一次乘法。

用 python 的一个优势是，不用考虑整数溢出的问题。

这里还有一个问题没有处理，就是 0。当时没考虑到，但是样例救了我，跑样例除了除零错误。

对于 0 的思路是，每次遇到 0 直接清空列表，因为前面是啥都没用了，只要超过 0 的位置，前面的都是 0 了。

而相应的查询的地方，长度超过列表长度，直接返回 0，因为面前肯定是遇到 0 了。

再一个为了代码方便，直接列表第一个默认自带一个 1。

### 代码

```python
class ProductOfNumbers:

    def __init__(self):
        self.p = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.p = [1]
        else:
            self.p.append(self.p[-1] * num)

    def getProduct(self, k: int) -> int:
        if k >= len(self.p): return 0
        return self.p[-1] // self.p[-k-1]
```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)