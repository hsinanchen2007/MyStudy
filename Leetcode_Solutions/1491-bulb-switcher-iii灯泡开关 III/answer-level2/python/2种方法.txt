# 方法一
灯的编号是由1到n排列的，当编号为i的灯变蓝时，那么1到i的灯必为蓝，此时组成一个等差数列，故我们用变量sum记录已打开的灯的编号的总和，当sum满足等差数列和时，那么此时所有打开的灯都为蓝。
```
class Solution(object):
    def numTimesAllBlue(self, light):
        """
        :type light: List[int]
        :rtype: int
        """
        res = 0
        sum = 0
        for i, l in enumerate(light):
            sum += l
            if sum == (i + 1) * (i + 2) // 2:
                res += 1
        return res
```
# 方法二
变量m记录已打开灯的最大编号，当m等于当前已打开灯的个数时，则编号1到m的灯都为蓝。
```
class Solution(object):
    def numTimesAllBlue(self, light):
        """
        :type light: List[int]
        :rtype: int
        """
        m = ans = 0
        for i in range(len(light)):#这里的i+1就对应已打开灯的数量
            m = max(m, light[i])
            if m == i+1:
                ans += 1
        return ans
```
