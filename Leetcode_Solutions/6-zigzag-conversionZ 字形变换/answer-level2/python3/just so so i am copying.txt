```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # 根据Z字转换的规律，从第一个数到最后一个数依次连续遍历，
        # 就能够得到最后的数值。
        # 难点就在于对于对的转折点的控制，也就是flag，为标志是否对于行来说是加还是减
        # 开辟一个数组，存储每一行的值，然后连起来即可
        if numRows == 1: return s 
        res = ['' for i in range(numRows)]

        currow, flag = 0, False
        for v in s:
            res[currow] += v
            if currow == 0 or currow == numRows - 1: flag = not flag
            currow += 1 if flag else -1

        ans = ''
        for v in res:
            ans += v 
        return ans 
```
