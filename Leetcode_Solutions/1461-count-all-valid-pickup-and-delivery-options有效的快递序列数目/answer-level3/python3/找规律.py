假设当前有3个快递，即有6个坑(如：(P1,P2,P3,D2,D1,D3))，序列数目为90
现在增加一个快递，则有了8个坑，取两个坑填充新快递的收件/配送(收件在前), 其余的坑按三个快递时进行填冲(如：(P1,P2,P3,X,D2,D1,D3,X))，则序列数目为：$90*C_8^2$
```
class Solution:
    def countOrders(self, n: int) -> int:
        res = 1
        for i in range(1, n+1):
            res *= i*(i*2-1)
            res = res % (10**9+7)
        return res
```
