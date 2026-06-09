先上结果：
![image.png](https://pic.leetcode-cn.com/a041922c4592863177f86826c987858f3ca333af2f81332873ad9b48a1260896-image.png)

如果是正常的26进制，其实不难

[@windliang](/u/windliang/)
![image.png](https://pic.leetcode-cn.com/b2f75268ca4cb535a87d64bd72d4211752dcb450cf5deec15ebe7e7735a27f25-image.png)

每次左右两边取模，就能得到各位数字

但这里不大一样，这里的A-Z表示1-26，并且

[@windliang](/u/windliang/)
*正常的 26 进制本应该满 26 进 1，然后低位补 0，但是这里满 26 的话就用 26 表示。满 27 的时候才会向前进 1，然后低位补 1。*

可以这么想，如果A-Z表示0-25，并且从0开始满26进位，A-Z完全可以参与26进制运算

```
class Solution:
    def convertToTitle(self, n: int) -> str:
        t = n
        s = ''
        while t > 0:                # 每次循环 是 每次取模得到数字 的过程
            t -= 1                  # 把 从1开始满27进位 变回 从0开始满26进位
            a, b = t//26, t%26      # 这里b的取值范围是0-25
            s = s + chr(b+65)       # A的ASCII码是65，b+65表示 0-25 和 A-Z 有了一一对应
            t = a
        return s[::-1]              # 最后将 优先获得的低位数字 反转到最后
```
