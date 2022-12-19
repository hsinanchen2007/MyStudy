### 解题思路
首先将二进制数转化为十进制，相加，再将十进制结果转化为二进制输出。在这里利用 python内置函数 int() 和 bin(),注意bin()输出结果开头为“0b...”，与题目要求结果略有不同。

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        dec_sum = int(a,2) + int(b,2)
        bin_sum = str(bin(dec_sum))[2:]
        return bin_sum
```