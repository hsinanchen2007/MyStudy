异或判断需要改变的位数，注意python3的数据溢出处理


```
class Solution:
    def convertInteger(self, A: int, B: int) -> int:
        #PYTHON 3 int为无限大，并不是3322位，需要数据溢出处理
        mask=0xFFFFFFFF
        A=mask&A
        B=mask&B
        return bin(A^B)[2:].count('1')
```
