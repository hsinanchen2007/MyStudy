![image.png](https://pic.leetcode-cn.com/c2be2817a667e8f0b7465757e8f0ebefae273e83c6b3f3e231fcf4f68e3d1280-image.png)
```
'''
dp(i) 表示i笔订单的处理可能方式
总共2i个位置要安排，最后一个肯定放D, 可以选择D1, D2 ..... Di
前面2i-1个位置选个一个放Pi

dp(i) = i * (2i-1) * dp(i-1)
'''

class Solution:
    def countOrders(self, n: int) -> int:
        if n == 1:
            return 1

        val = 1
        for i in range(2, n+1):
            val *= (i* (2*i-1)) % 1000000007
            val %= 1000000007
        return val
```
