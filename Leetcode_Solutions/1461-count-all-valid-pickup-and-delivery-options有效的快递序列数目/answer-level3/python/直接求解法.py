# 思路
不考虑非法情况下，n个订单的收、发共有 **(2n)!**种全排列。
其中每个订单的收、发有固定的顺序，因此对于每个订单只有**一半的全排列**满足条件。
故最终结果是 **(2n)!/(2^n)**
# 代码
```
class Solution:
    def countOrders(self, n: int) -> int:
        rst=1
        for i in range(1,n+1):
            rst*=i*(n+i)
            rst/=2
            rst%=(1e9+7)
        return int(rst)
```
