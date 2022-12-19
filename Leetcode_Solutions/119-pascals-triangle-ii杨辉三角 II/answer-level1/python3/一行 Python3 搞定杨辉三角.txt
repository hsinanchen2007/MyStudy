**这里的一行不包括引入包和返回**

## 思路
很多人已经讲了很多，就是用组合数公式来算。个人认为如果没发现杨辉三角的规律是组合数公式那这题其实还蛮难的。

不同于很多题解，这里调用了计算组合数的包，在scipy.special当中。需要注意的是，它返回的是小数类型（组合数为什么要返回一个小数，估计是后面数字大了计算不精确？），要转换成整数。不能直接int()，要先round()四舍五入一下，因为会出现xxxxx.99997这种情况。

当然省资源的方法应该是算了前一半代码，后面直接拷贝自身的逆序，这里为了省代码行数，没有这么做。

## 代码
```
from scipy.special import comb
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [int(round(comb(rowIndex,i))) for i in range(rowIndex + 1)]
        return ans
```