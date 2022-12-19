初始化为1到n，此时差值为1种，然后从第二位到末位开始不停翻转即可，翻转一次增加一种差值
```
    def constructArray(self, n: int, k: int) -> List[int]:
        res = list(range(1, n + 1))  # 刚开始有一个不同的差绝对值
        for i in range(1, k):  # 每翻转后面一次产生一个新的
            res[i:] = res[:i-1:-1]  # 翻转
        return res
```
