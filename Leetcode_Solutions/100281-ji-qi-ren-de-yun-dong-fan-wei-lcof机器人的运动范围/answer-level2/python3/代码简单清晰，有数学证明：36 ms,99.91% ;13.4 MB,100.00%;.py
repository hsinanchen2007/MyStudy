### 解题思路

block函数返回长宽为m,n的块里面，和最大值为k的可到达区域（m,n<=9）。

主函数将所有区域划分为`10*10`的小块，每个小块的左下角坐标为`(a*10,b*10)`,输入到block中的k为`k-a-b`。

其中需要判断机器人能否从原点走到这个小块的左下角，这里证明只要满足`k>=a+b-1+9`即可，证明如下：

若可到达`(a*10,b*10)`需先到达`(a*10-1,b*10)`或`(a*10,b*10-1)`,此两点数位之和为a+b-1+9；

从原点出发，先沿着y轴走到`(0,b*10)`，路中数位之和最大值为b-1+9<=a+b-1+9;
再向x轴方向走到`(a*10,b*10)`，路中数位之和最大值为a+b-1+9;
故如果`k>=a+b-1+9`，则可以从原点走到`(a*10,b*10)`，注意a=b=0需要单独判断。
那么下面只要遍历就好了，都是数学计算。

### 代码

```python3
def block(m, n, k):
    if m > n: m, n = n, m
    if k <= m:
        return ((k + 1) * (k + 2)) >> 1
    elif k <= n:
        return (((m + 1) * (m + 2)) >> 1) + (k - m) * (m + 1)
    elif k <= m + n:
        return (m + 1) * (n + 1) - (((m + n - k) * (m + n - k + 1)) >> 1)
    else:
        return (m + 1) * (n + 1)


class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        a, b = 0, 0
        rst = 0
        while a * 10 < m:
            b = 0
            while b * 10 < n:
                if (a == 0 and b == 0) or k > a + b + 7:
                    mm = 9 if m - 1 - a * 10 > 9 else m - 1 - a * 10
                    nn = 9 if n - 1 - b * 10 > 9 else n - 1 - b * 10
                    rst += block(mm, nn, k - a - b)
                b += 1
            a += 1
        return rst
```