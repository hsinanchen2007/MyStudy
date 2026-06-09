这个题难倒我的是关于遍历、集合、字典的一些操作。特别是遍历，一旦遍历的方式不对，提交就会超时。

`{*range(self.line,N)}-set(blacklist)`
上面这句等价于：
`{for i in range(self.line,N)-set(blacklist)}`
我原来是下面这么写的，我以为都一样，但就会导致超时无法通过，或者能通过，时间很长：
`{for i in range(self.line,N) if i not in blacklist}`
后来反思了一下，这么写相当于两个遍历叠加在一起，自然效率极差。
而`{i for i in blacklist if i <self.line}`虽然也是两个条件，第二个条件是不需要遍历的，只是纯判断，这有本质区别。


    def __init__(self, N, blacklist):
        self.line = N - len(blacklist)
        self.dic = dict(zip(
            {i for i in blacklist if i <self.line},
            {*range(self.line,N)}-set(blacklist)
            ))

    def pick(self) -> int:
        import random
        r = random.randint(0,self.line-1)
        return r if r not in self.dic else self.dic[r]


另一点学习的地方是，原来我是建立“白名单”的对应，导致建出来的字典占的内存非常大，查找效率也低。现在这个方法至多是建黑名单大小的字典。