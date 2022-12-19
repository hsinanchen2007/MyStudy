### 解题思路
这个很容易想到用数组，得到x中的每一个数字，那就可以随便操作了。
实际操作中发现通过for循环，不需要数组，因为已经知道了x是几位数。
另外，特殊情况数值范围[−2^31,  2^31 − 1]。
一开始我知道有这种特殊情况，但是不知道怎么处理，后来我就用了最简单的判别方法，没想到通过了，这个我还是有点懵。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if x == 0:
            return x
        x_abs = abs(x)

        # 获取x是几位数
        num = 1
        while int(x_abs / pow(10, num)) != 0:
            num += 1

        reverse_abs = 0
        reverse = 0

        for i in range(0,num):
            temp = int( x_abs / pow(10,i) ) % 10
            reverse_abs += temp * pow(10, num - i - 1)

        if x < 0:
            reverse = 0 - reverse_abs
        else:
            reverse = reverse_abs

        #  数值范围[−2^31,  2^31 − 1]
        if reverse < 0 - pow(2,31) or reverse_abs > pow(2,31) - 1:
            return 0
        else:
            return reverse
```