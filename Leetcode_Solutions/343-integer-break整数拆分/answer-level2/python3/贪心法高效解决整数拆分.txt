![bc3f55ebf8c022e9ce60fb6c9ed428f.png](https://pic.leetcode-cn.com/1a5917bcb81957c89fc59bef9f747f667c8934a5d5d3f017626f287ed201d461-bc3f55ebf8c022e9ce60fb6c9ed428f.png)

### 解题思路
贪心策略
（1） n为2,3,4时，由于必须拆分为两个数，需要特殊处理。
（2）当n大于4时，应该尽可能的多拆出3。这是由于3*2 > 5（=3+2）, 3*3 > 2*2*2>（6、7）。故当n>3时，拆出3，直至小于等于4，在用拆出的3乘以剩余的数。

### 代码

```python3
class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2:
            return 1
        if n == 3:
            return 2
        if n == 4:
            return 4
        
        # res = 1
        # while n >= 5:
        #     res *= 3
        #     n -= 3
        # res *= n
        # return res

        # compute the total number of 3 directly and get result dierctly
        if n % 3 == 0:
            return 3 ** (n // 3)
        elif n % 3 == 2:
            return (3 ** (n // 3)) * 2
        else:
            return (3 ** (n // 3 - 1)) * 4
        
```
# 空间复杂度
1 时间复杂度
O(1)
2 空间复杂度
O(1)