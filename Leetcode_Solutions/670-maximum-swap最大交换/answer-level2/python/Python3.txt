直接贴代码吧，思路也写在代码里了
```
class Solution:
    def maximumSwap(self, num: int) -> int:
        '''
        若最高位数字不是最大，则将其余位中的最大数字与最高位交换。
            若其余位中的最大数字不止一个，则将位数最低的那个与最高位交换。
        若最高位数字是最大，则对除去最高位的剩余数字进行递归操作。
        '''
        s, a = str(num), []
        for val in s:
            a.append(int(val))
        b = sorted(a, reverse = True)
        if a == b:
            return num
        i, l = 0, len(a)
        while i < l:
            if a[i] == b[i]:
                i += 1
            else:break
        for j in range(l-1, -1, -1):
            if a[j] == b[i]:
                a[j] = a[i]
                a[i] = b[i]
                break
        s = ''
        for x in a:
            s += str(x)
        return int(s)
```
为了获得顺序相同的数组，用了str操作的笨办法。

j从后往前遍历，是为了保证当出现多个最大数值时，使位最低的那个发生交换。